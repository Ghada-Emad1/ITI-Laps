<?php

$skills = isset($_POST['skills']) && is_array($_POST['skills']) ? implode(",", $_POST['skills']) : "None";
//echo $skills;
$_POST['skills']=$skills;
$data=implode("-",$_POST);
echo $data;
file_put_contents('data.txt',"\n".$data,FILE_APPEND);

echo '<a href="list.php">Show Table</a>'


?>