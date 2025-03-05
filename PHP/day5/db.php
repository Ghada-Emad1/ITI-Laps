<?php
require 'vaildator.php';
class Db
{
    private $host = 'localhost';
    private $dbname = "php_45";
    private $password = "94148260"; 
    private $user = "root";
    private $connection;
    private $validator;

    public function __construct()
    {

        $this->connection = new PDO("mysql:host=$this->host;dbname=$this->dbname",$this->user,$this->password);
        $this->validator=new Validator();
    }

    public function getConnection()
    {
        return $this->connection;
    }

    public function getData($table_name, $cond = "1")
    {
        $stmt = $this->connection->prepare("SELECT * FROM $table_name WHERE $cond");
        $stmt->execute();
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function deleteUser($userId)
    {
        try {
            // Delete user skills first (to maintain referential integrity)
            $stmt = $this->connection->prepare("DELETE FROM user_skills WHERE user_id = ?");
            $stmt->execute([$userId]);

            // Then delete the user
            $stmt = $this->connection->prepare("DELETE FROM users WHERE id = ?");
            return $stmt->execute([$userId]); // Returns true if successful
        } catch (PDOException $e) {
            return "Error: " . $e->getMessage();
        }
    }

    public function getUsersWithSkills()
    {
        try {
            $sql = "
                SELECT users.id, users.first_name, users.last_name, users.address, users.department,
                users.country, users.gender, users.username, users.img,
                GROUP_CONCAT(user_skills.skill SEPARATOR ', ') AS skills 
                FROM users
                LEFT JOIN user_skills ON users.id = user_skills.user_id
                GROUP BY users.id
            ";

            $stmt = $this->connection->prepare($sql);
            $stmt->execute();
            return $stmt->fetchAll(PDO::FETCH_ASSOC);
        } catch (PDOException $e) {
            return "Error: " . $e->getMessage();
        }
    }


    public function getUserById($userId)
    {
        if (!is_numeric($userId)) {
            return null; 
        }

        $stmt = $this->connection->prepare("SELECT * FROM users WHERE id = ?");
        $stmt->execute([$userId]);
        $user = $stmt->fetch(PDO::FETCH_ASSOC);

        return $user ?: null;
    }

    public function getUserSkills($userId)
    {
        $stmt = $this->connection->prepare("SELECT skill FROM user_skills WHERE user_id = ?");
        $stmt->execute([$userId]);
        return $stmt->fetchAll(PDO::FETCH_COLUMN) ?: [];
    }

    public function getTitle($gender)
    {
        return (strtolower($gender) == 'female') ? "Miss" : "Mr";
    }

    public function updateUser($userId, $data)
    {
        $stmt = $this->connection->prepare("UPDATE users SET first_name = ?, last_name = ?, address = ?, country = ?, gender = ?, username = ?, img = ? WHERE id = ?");
        return $stmt->execute([
            $data['fname'],
            $data['lname'],
            $data['address'],
            $data['country'],
            $data['gender'],
            $data['username'],
            $data['img'],
            $userId
        ]);
    }

    public function updateUserSkills($userId, $skills)
    {
        $stmt = $this->connection->prepare("DELETE FROM user_skills WHERE user_id = ?");
        $stmt->execute([$userId]);

        if (!empty($skills)) {
            $stmt = $this->connection->prepare("INSERT INTO user_skills (user_id, skill) VALUES (?, ?)");
            foreach ($skills as $skill) {
                $stmt->execute([$userId, $skill]);
            }
        }
    }


    public function registerUser($data, $files)
    {
        if (isset($_POST['register'])) {

            try {
                $errors = [];
                if ($_SERVER["REQUEST_METHOD"] == "POST") {
                    $fname = $this->validator->validate($_POST['fname']);
                    $lname = $this->validator->validate($_POST['lname']);
                    $address = $this->validator->validate($_POST['address']);
                    $country = $this->validator->validateCountry($_POST['country'], $errors);
                    $gender = $this->validator->validateGender($_POST['gender'], $errors);
                    $username = $this->validator->validate($_POST['username']);
                    $department = $this->validator->validate($_POST['department']);
                    $password = $this->validator->validatePassword($_POST['password'], $errors);
                    if (isset($files['img']) && $files['img']['error'] == 0) {
                        $image = $files['img'];
                    } else {
                        $errors['img'] = "Please upload an image.";
                    }

                    if (isset($_POST['skills'])) {
                        $skills = $this->validator->validateSkills($_POST['skills'], $errors);
                    } else {
                        $errors['skills'] = "Please select at least one skill";
                        $skills = [];
                    }

                   



                    if (strlen($fname) < 2) {
                        //error
                        $errors['fname'] = "Not Valid First Name";
                    }
                    if (strlen($lname) < 2) {
                        //error
                        $errors['lname'] = "Not Valid Last Name";
                    }
                    if (strlen($department) < 2) {
                        //error
                        $errors['department'] = "Not Valid Department";
                    }
                    if (strlen($address) < 2) {
                        //error
                        $errors['address'] = "Not Valid Address";
                    }
                    if (strlen($username) < 2) {
                        //error
                        $errors['username'] = "Not Vaild User Name";
                    }
                    if ($_FILES["img"]["size"] < 1000) {
                        $errors['img'] = 'Not Valid Image';
                    }
                    if (count($errors) > 0) {
                        $data = json_encode($errors);
                        header("Location:Registeration.php?errors=" . $data);
                    } else {
                        move_uploaded_file($files['img']['tmp_name'], "images/" . $files['img']['name']);
                        $stmt = $this->connection->prepare("INSERT INTO users (first_name, last_name, address, country, gender, username,password, department,img) 
                                      VALUES (?, ?, ?, ?, ?, ?, ?,?,?)");
                        $stmt->execute([$fname, $lname, $address, $country, $gender, $username, $password, $department, $_FILES['img']['name']]);

                        // Get last inserted user ID
                        $user_id = $this->connection->lastInsertId();
                        $skillStmt = $this->connection->prepare("INSERT INTO user_skills (user_id, skill) VALUES (?, ?)");
                        foreach ($skills as $skill) {
                            $skillStmt->execute([$user_id, $skill]);
                        }

                        echo "User registered successfully!";
                        header("location:login.php");
                    }
                }
            } catch (PDOException $e) {
                echo "Connection failed: " . $e->getMessage();
            }
        }
        
    }
}