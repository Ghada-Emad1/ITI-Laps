<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['gender']) && $_POST['gender'] == 'female') {
        echo "<h3>Thanks Ms. {$_POST['fname']} {$_POST['lname']}</h3>";
    } else {
        echo "<h3>Thanks Mr. {$_POST['fname']} {$_POST['lname']}</h3>";
    }

    echo "<h3>Please Review Your Information</h3>";
    echo "Your Name is {$_POST['fname']} {$_POST['lname']}";
    echo "<br>";
    echo "Your Address is {$_POST['address']}";
    echo "<br>";

    if (isset($_POST['skills']) && is_array($_POST['skills'])) {
        for ($i = 0; $i < count($_POST['skills']); $i++) {
            if (count($_POST['skills']) >= 1) {
                echo "Your Skills are : {$_POST['skills'][$i]}";
            } else {
                echo "No Skills Found";
            }
        }
    }
    
   

    echo "<br>";
    echo "Department is: {$_POST['department']}";
}
