<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    require "db.php";
    
    if (isset($_GET['id']) && is_numeric($_GET['id'])) {
        $user = new Db();
        $result = $user->deleteUser($_GET['id']);

        if ($result === true) {
            header("Location: list.php");
            exit;
        } else {
            echo "Failed to delete user: " . $result;
        }
    } else {
        echo "Invalid user ID.";
    }



    ?>
</body>

</html>