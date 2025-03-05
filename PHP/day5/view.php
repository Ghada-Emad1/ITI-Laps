<?php
require 'db.php';

if (!isset($_GET['id'])) {
    die("Invalid user ID.");
}

$userId = $_GET['id'];

$userObj = new Db();
$user = $userObj->getUserById($userId);

if (!$user) {
    die("User not found.");
}

$skills = $userObj->getUserSkills($userId);
$title = $userObj->getTitle($user['gender']);

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Details</title>
</head>

<body>
    <h2><?php echo $title . " " . htmlspecialchars($user['first_name']) . " " . htmlspecialchars($user['last_name']); ?></h2>
    <p><strong>Address:</strong> <?php echo htmlspecialchars($user['address']); ?></p>
    <p><strong>Country:</strong> <?php echo htmlspecialchars($user['country']); ?></p>
    <p><strong>Gender:</strong> <?php echo htmlspecialchars($user['gender']); ?></p>
    <p><strong>Username:</strong> <?php echo htmlspecialchars($user['username']); ?></p>
    <p><strong>Department:</strong> <?php echo htmlspecialchars($user['department']); ?></p>
    <p><strong>Skills:</strong> <?php echo $skills ? implode(", ", $skills) : "No skills listed"; ?></p>

    <img src="images/<?php echo htmlspecialchars($user['img']); ?>" width="200" height="100" alt="User Image">
</body>

</html>