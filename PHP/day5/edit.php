<?php
require_once 'db.php';

if (!isset($_GET['id']) || !is_numeric($_GET['id'])) {
    die("Invalid user ID.");
}

$userId = $_GET['id'];
$userObj = new Db();
$user = $userObj->getUserById($userId);

if (!$user) {
    die("User not found.");
}

$skills = $userObj->getUserSkills($userId);

// Handle Form Submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $userData = [
        'fname' => $_POST['fname'],
        'lname' => $_POST['lname'],
        'address' => $_POST['address'],
        'country' => $_POST['country'],
        'gender' => $_POST['gender'],
        'username' => $_POST['username'],
        'img' => $_POST['img']
    ];
    $selectedSkills = $_POST['skills'] ?? [];

    // Update user details and skills
    $userObj->updateUser($userId, $userData);
    $userObj->updateUserSkills($userId, $selectedSkills);

    header("Location: list.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <title>Edit User</title>
</head>

<body>
    <form action="edit.php?id=<?= $userId ?>" method="post" class="m-4">
        <div class="mb-3">
            <label for="fname" class="form-label">First Name</label>
            <input id="fname" type="text" name="fname" class="form-control" value="<?= htmlspecialchars($user['first_name']) ?>">
        </div>

        <div class="mb-3">
            <label for="lname" class="form-label">Last Name</label>
            <input id="lname" type="text" name="lname" class="form-control" value="<?= htmlspecialchars($user['last_name']) ?>">
        </div>

        <div class="mb-3">
            <label for="address" class="form-label">Address</label>
            <textarea class="form-control" id="address" name="address"><?= htmlspecialchars($user['address']) ?></textarea>
        </div>

        <div class="mb-3">
            <label for="country" class="form-label">Country</label>
            <select class="form-select" id="country" name="country">
                <option value="Egypt" <?= $user['country'] == 'Egypt' ? 'selected' : '' ?>>Egypt</option>
                <option value="Canada" <?= $user['country'] == 'Canada' ? 'selected' : '' ?>>Canada</option>
                <option value="Korea" <?= $user['country'] == 'Korea' ? 'selected' : '' ?>>Korea</option>
            </select>
        </div>

        <div class="mb-3">
            <label class="form-label">Gender</label>
            <div class="form-check">
                <input class="form-check-input" type="radio" name="gender" id="male" value="male" <?= $user['gender'] == 'male' ? 'checked' : '' ?>>
                <label class="form-check-label" for="male">Male</label>
            </div>
            <div class="form-check">
                <input class="form-check-input" type="radio" name="gender" id="female" value="female" <?= $user['gender'] == 'female' ? 'checked' : '' ?>>
                <label class="form-check-label" for="female">Female</label>
            </div>
        </div>

        <div class="mb-3">
            <label class="form-label">Skills</label>
            <div class="form-check">
                <input type="checkbox" id="php" name="skills[]" value="PHP" <?= in_array('PHP', $skills) ? 'checked' : '' ?>>
                <label for="php">PHP</label>
            </div>
            <div class="form-check">
                <input type="checkbox" id="j2se" name="skills[]" value="J2SE" <?= in_array('J2SE', $skills) ? 'checked' : '' ?>>
                <label for="j2se">J2SE</label>
            </div>
            <div class="form-check">
                <input type="checkbox" id="mysql" name="skills[]" value="MySQL" <?= in_array('MySQL', $skills) ? 'checked' : '' ?>>
                <label for="mysql">MySQL</label>
            </div>
            <div class="form-check">
                <input type="checkbox" id="pgsql" name="skills[]" value="PostgreSQL" <?= in_array('PostgreSQL', $skills) ? 'checked' : '' ?>>
                <label for="pgsql">PostgreSQL</label>
            </div>
        </div>

        <div class="mb-3">
            <label for="username" class="form-label">Username</label>
            <input id="username" type="text" name="username" class="form-control" value="<?= htmlspecialchars($user['username']) ?>">
        </div>


        <fieldset>
            <div class="mb-3">
                <label for="department" class="form-label">Department</label>
                <input type="text" id="department" class="form-control" name="department" value="Open Source" readonly>
            </div>
        </fieldset>
        <div class="mb-3">
            <label class="form-label">Current Image</label><br>
            <?php if (!empty($user['img'])) : ?>
                <img src="images/<?= htmlspecialchars($user['img']) ?>" alt="User Image" width="100"><br>
            <?php endif; ?>
            <label class="form-label">Upload New Image</label>
            <input type="file" name="img">
        </div>
        <button type="submit" class="btn btn-primary">Submit</button>
        <a href="list.php" class="btn btn-secondary">Cancel</a>
    </form>
</body>

</html>