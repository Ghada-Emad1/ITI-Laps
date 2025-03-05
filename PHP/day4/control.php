<?php
$connection = new PDO("mysql:host=localhost;dbname=php_45", "root", "94148260");

if (isset($_POST['register'])) {

    try {
        $errors = [];
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $fname = validate($_POST['fname']);
            $lname = validate($_POST['lname']);
            $address = validate($_POST['address']);
            $country = validateCountry($_POST['country'],$errors);
            $gender = validateGender($_POST['gender'],$errors);
            $username = validate($_POST['username']);
            $department = validate($_POST['department']);
            $password = vaildatePassword($_POST['password'], $errors);

            if (isset($_POST['skills'])) {
                $skills = validateSkills($_POST['skills'], $errors);
            } else {
                $errors['skills'] = "Please select at least one skill";
                $skills = [];
            }
          
            if (isset($_FILES['img']) && $_FILES['img']['error'] == 0) {
                $image = $_FILES['img'];
            } else {
                $errors['img'] = "Please upload an image.";
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
            if($_FILES["img"]["size"]<1000){
                $errors['img']='Not Valid Image';
            }
            if (count($errors) > 0) {
                $data=json_encode($errors);
                header("Location:Registeration.php?errors=".$data);
            } else {
                move_uploaded_file($_FILES['img']['tmp_name'],"images/". $_FILES['img']['name']);
                $stmt = $connection->prepare("INSERT INTO users (first_name, last_name, address, country, gender, username,password, department,img) 
                                      VALUES (?, ?, ?, ?, ?, ?, ?,?,?)");
                $stmt->execute([$fname, $lname, $address, $country, $gender, $username, $password, $department, $_FILES['img']['name']]);

                // Get last inserted user ID
                $user_id = $connection->lastInsertId();
                $skillStmt = $connection->prepare("INSERT INTO user_skills (user_id, skill) VALUES (?, ?)");
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

if(isset($_POST['Login'])){
 
    $stm=$connection->prepare("select * from users where username=? and password=?");
    $stm->execute([$_POST['username'],$_POST['password']]);
    var_dump($stm);
    if($data=$stm->fetch(PDO::FETCH_ASSOC)){
      session_start();
      $_SESSION['fname']=$data['fname'];
      $_SESSION['lname']=$data['lname'];
      header("Location:list.php");
    }else{
        header("Location:login.php?error=1");
    }
}
function validate($data)
{
    $data = trim($data);
    stripslashes($data);
    htmlspecialchars($data);
    return $data;
}
function validateCountry($country,&$errors){
    $allowedCountry=['Africa','South America','North America','Europe'];
    if(!in_array($country,$allowedCountry)){
      $errors['country']="Please Select a valid Country";
    }
    return validate($country);
}
function validateGender($gender,&$errors){
    $allowedGender=['female','male'];
    if(!in_array($gender,$allowedGender)){
        $errors['gender']="Please Enter Valid gender";
    }
    return validate($gender);
}

function validateSkills($skills, &$errors)
{
    if (!is_array($skills) || empty($skills)) {
        $errors['skills'] = "Please select at least one skill";
        return [];
    }

    $allowedSkills = ["PHP", "J2SE", "MySQL", "PostgreSQL"];
    $validatedSkills = [];

    foreach ($skills as $skill) {
        $skill = trim(htmlspecialchars($skill));
        if (in_array($skill, $allowedSkills)) {
            $validatedSkills[] = $skill;
        }
    }

    if (empty($validatedSkills)) {
        $errors['skills'] = "Please select a valid skill";
    }

    return $validatedSkills;
}
function vaildatePassword($password,&$errors){
if(empty($password)|| strlen($password)<0){
    $errors['password']="Password must be at least 6 character";
}
return $password;
}

function validateImage($img, &$errors)
{
    if ($img['size'] > 500000) { 
        $errors['img'] = "Image file size should be less than 500KB.";
        return false;
    }

    $allowedTypes = ['image/jpg','image/jpeg', 'image/png', 'image/gif'];
    if (!in_array($img['type'], $allowedTypes)) {
        $errors['img'] = "Only JPG, PNG, and GIF files are allowed.";
        return false;
    }

    return true;
}
