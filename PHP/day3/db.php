<?php
try {
    $connection = new PDO("mysql:host=localhost;dbname=php_45", "root", "94148260");
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $fname = $_POST['fname'];
        $lname = $_POST['lname'];
        $address = $_POST['address'];
        $country = $_POST['country'];
        $gender = $_POST['gender'];
        $username = $_POST['username'];
        $department = $_POST['department'];
        $skills = isset($_POST['skills']) ? $_POST['skills'] : []; 

        $stmt = $connection->prepare("INSERT INTO users (first_name, last_name, address, country, gender, username, department) 
                                      VALUES (?, ?, ?, ?, ?, ?, ?)");
        $stmt->execute([$fname, $lname, $address, $country, $gender, $username, $department]);
        $user_id = $connection->lastInsertId();
        $skillStmt = $connection->prepare("INSERT INTO user_skills (user_id, skill) VALUES (?, ?)");
        foreach ($skills as $skill) {
            $skillStmt->execute([$user_id, $skill]);
        }

        echo "User registered successfully!";
        header("location:list.php");
    }
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
