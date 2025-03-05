<?php
// Database connection
try {
    $connection = new PDO("mysql:host=localhost;dbname=php_45", "root", "94148260");
    $connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Validate user ID
    if (!isset($_GET['id']) || !is_numeric($_GET['id'])) {
        die("Invalid user ID.");
    }

    $userId = $_GET['id'];

    // Fetch user data
    $stmt = $connection->prepare("SELECT * FROM users WHERE id = ?");
    $stmt->execute([$userId]);
    $user = $stmt->fetch(PDO::FETCH_ASSOC);

    if (!$user) {
        die("User not found.");
    }

    // Fetch user skills
    $stmt = $connection->prepare("SELECT skill FROM user_skills WHERE user_id = ?");
    $stmt->execute([$userId]);
    $skills = $stmt->fetchAll(PDO::FETCH_COLUMN);

    // Ensure skills is an array
    if (!$skills) {
        $skills = [];
    }

    // Determine title based on gender (case insensitive)
    $title = (strtolower($user['gender']) == 'female') ? "Miss" : "Mr";
} catch (PDOException $e) {
    die("Connection failed: " . $e->getMessage());
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Details</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <div class="container mt-5">
        <h1>Hello <?= htmlspecialchars($title . " " . $user['first_name'] . " " . $user['last_name']) ?></h1>
        <table class="table table-bordered">
            <tr>
                <th>First Name</th>
                <td><?= htmlspecialchars($user['first_name']) ?></td>
            </tr>
            <tr>
                <th>Last Name</th>
                <td><?= htmlspecialchars($user['last_name']) ?></td>
            </tr>
            <tr>
                <th>Address</th>
                <td><?= htmlspecialchars($user['address']) ?></td>
            </tr>
            <tr>
                <th>Department</th>
                <td><?= htmlspecialchars($user['department']) ?></td>
            </tr>
            <tr>
                <th>Country</th>
                <td><?= htmlspecialchars($user['country']) ?></td>
            </tr>
            <tr>
                <th>Gender</th>
                <td><?= htmlspecialchars($user['gender']) ?></td>
            </tr>
            <tr>
                <th>Skills</th>
                <td><?= !empty($skills) ? htmlspecialchars(implode(", ", $skills)) : "No skills listed" ?></td>
            </tr>
            <tr>
                <th>Username</th>
                <td><?= htmlspecialchars($user['username']) ?></td>
            </tr>
        </table>
        <a href="javascript:history.back()" class="btn btn-secondary">Back</a>
    </div>
</body>

</html>