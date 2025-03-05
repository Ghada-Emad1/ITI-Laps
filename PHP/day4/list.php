<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Users List</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <?php
     session_start();
     if(!isset($_SESSION['fname'])){
        header("Location:login.php");
     }
    
    ?>
    <div class="container mt-4">
        <h2 class="text-center mb-3">Users List</h2>
        <table class="table table-striped">
            <thead>
                <tr>
                    <th>First Name</th>
                    <th>Last Name</th>
                    <th>Address</th>
                    <th>Department</th>
                    <th>Country</th>
                    <th>Gender</th>
                    <th>Username</th>
                    <th>Img</th>
                    <th>Skills</th>

                </tr>
            </thead>
            <tbody>

                <?php
                try {
                    $connection = new PDO("mysql:host=localhost;dbname=php_45", "root", "94148260");

                    $sql = "
                    SELECT users.id, users.first_name, users.last_name, users.address, users.department,
                    users.country, users.gender, users.username, users.img,
                    GROUP_CONCAT(user_skills.skill SEPARATOR ', ') AS skills 
                    FROM users
                    LEFT JOIN user_skills ON users.id = user_skills.user_id
                    GROUP BY users.id
                ";

                    $stmt = $connection->prepare($sql);
                    $stmt->execute();
                    $users = $stmt->fetchAll(PDO::FETCH_ASSOC);

                    foreach ($users as $user) {
                        echo "<tr>";
                        foreach ($user as $key => $value) {
                            if ($key === "img") {
                                echo "<td><img src='images/$value' width='200' height='100' alt='user image'/></td>";
                            } elseif ($key !== "id") { 
                                echo "<td>$value</td>";
                            }
                        }

                        echo "<td>
                                <a href='view.php?id={$user['id']}' class='btn btn-primary'>View</a>
                                <a href='delete.php?id={$user['id']}' class='btn btn-danger'>Delete</a>
                                <a href='edit.php?id={$user['id']}' class='btn btn-warning'>Edit</a>
                          </td>";

                        echo "</tr>";
                    }
                } catch (PDOException $e) {
                    echo "<tr><td colspan='9' class='text-danger text-center'>Connection failed: " . $e->getMessage() . "</td></tr>";
                }
                ?>

            </tbody>
        </table>
    </div>
</body>

</html>