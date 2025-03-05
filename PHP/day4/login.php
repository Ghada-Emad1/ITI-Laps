<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<?php

if(isset($_GET['error'])){
    echo "Invalid Data";
}else{
    header("Location:list.php");
}



?>

<body>
    <div class="container mt-5">
        <div class="row justify-content-center">
            <div class="col-md-4">
                <div class="card shadow-lg">
                    <div class="card-body">
                        <h3 class="text-center mb-4">Login</h3>
                        <form action="control.php" method="post">
                            <div class="mb-3">
                                <label for="username" class="form-label">Username</label>
                                <input type="text" class="form-control" id="username" name="username" placeholder="Enter User Name" required>
                            </div>
                            <div class="mb-3">
                                <label for="password" class="form-label">Password</label>
                                <input type="password" class="form-control" id="password" name="pass" placeholder="Enter Password" required>
                            </div>
                            <div class="d-grid">
                                <input type="submit" name="Login" value="Login" class="btn btn-primary">
                                
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>

</html>