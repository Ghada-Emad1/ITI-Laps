<?php
require "db.php";

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $user = new Db();
    $user->registerUser($_POST, $_FILES);
}
