<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task1 - Bootstrap Form</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body class="bg-light">

    <div class="container mt-5">
        <div class="card shadow-lg p-4">
            <h2 class="text-center mb-4">User Registration Form</h2>
            <form action="done.php" method="post">
                <div class="row">
                    <!-- First Name -->
                    <div class="col-md-6 mb-3">
                        <label class="form-label">First Name</label>
                        <input type="text" name="fname" class="form-control" placeholder="Enter First Name">
                    </div>
                    <!-- Last Name -->
                    <div class="col-md-6 mb-3">
                        <label class="form-label">Last Name</label>
                        <input type="text" name="lname" class="form-control" placeholder="Enter Last Name">
                    </div>
                </div>

                <!-- Address -->
                <div class="mb-3">
                    <label class="form-label">Address</label>
                    <textarea name="address" class="form-control" rows="3" placeholder="Enter your address"></textarea>
                </div>

                <!-- Country -->
                <div class="mb-3">
                    <label class="form-label">Country</label>
                    <select name="country" class="form-select">
                        <option disabled selected>Select Country</option>
                        <option value="Africa">Africa</option>
                        <option value="South America">South America</option>
                        <option value="North America">North America</option>
                        <option value="Europe">Europe</option>
                    </select>
                </div>

                <!-- Gender -->
                <div class="mb-3">
                    <label class="form-label">Gender</label>
                    <div class="form-check">
                        <input type="radio" name="gender" value="male" class="form-check-input" id="male">
                        <label class="form-check-label" for="male">Male</label>
                    </div>
                    <div class="form-check">
                        <input type="radio" name="gender" value="female" class="form-check-input" id="female">
                        <label class="form-check-label" for="female">Female</label>
                    </div>
                </div>

                <!-- Skills -->
                <div class="mb-3">
                    <label class="form-label">Skills</label>
                    <div class="form-check">
                        <input type="checkbox" name="skills[]" value="PHP" class="form-check-input" id="php">
                        <label class="form-check-label" for="php">PHP</label>
                    </div>
                    <div class="form-check">
                        <input type="checkbox" name="skills[]" value="J2SE" class="form-check-input" id="j2se">
                        <label class="form-check-label" for="j2se">J2SE</label>
                    </div>
                    <div class="form-check">
                        <input type="checkbox" name="skills[]" value="MySQL" class="form-check-input" id="mysql">
                        <label class="form-check-label" for="mysql">MySQL</label>
                    </div>
                    <div class="form-check">
                        <input type="checkbox" name="skills[]" value="PostgreSQL" class="form-check-input" id="pgsql">
                        <label class="form-check-label" for="pgsql">PostgreSQL</label>
                    </div>
                </div>

                <!-- Username & Password -->
                <div class="row">
                    <div class="col-md-6 mb-3">
                        <label class="form-label">Username</label>
                        <input type="text" name="username" class="form-control" placeholder="Enter Username">
                    </div>
                    <div class="col-md-6 mb-3">
                        <label class="form-label">Password</label>
                        <input type="password" name="password" class="form-control" placeholder="Enter Password">
                    </div>
                </div>

                <!-- Department (Disabled) -->
                <div class="mb-3">
                    <label class="form-label">Department</label>
                    <input type="text" class="form-control" name="department" value="Open Source" >
                </div>

                <!-- Submit & Reset Buttons -->
                <div class="text-center">
                    <button type="submit" class="btn btn-primary me-2">Submit</button>
                    <button type="reset" class="btn btn-secondary">Reset</button>
                </div>
            </form>
        </div>
    </div>

</body>

</html>