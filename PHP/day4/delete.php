<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    $userId = $_GET['id'];

    echo $index;

    $connection = new PDO("mysql:host=localhost;dbname=php_45", "root", "94148260");

    try {
        $stmt = $connection->prepare("DELETE FROM user_skills WHERE user_id = ?");
        $stmt->execute([$userId]);

        $stmt = $connection->prepare("DELETE FROM users WHERE id = ?");
        $stmt->execute([$userId]);

        header("Location:list.php");
    } catch (PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }



    ?>
</body>

</html>