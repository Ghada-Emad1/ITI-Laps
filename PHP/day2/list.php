<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Listing Contents</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">

</head>

<body>
    <table class="table table-striped">
        <thead>
            <tr>
                <td>First Name</td>
                <td>Last Name</td>
                <td>Address</td>
                <td>Country</td>
                <td>Gender</td>
                <td>Skills</td>
                <td>Email</td>
                <td>Department</td>
                <td>Show Details</td>
                <td>Delete</td>

            </tr>

        </thead>
        
        <?php
        $data=file('data.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
        foreach($data as $row){
            echo"<tbody>";
               $emp=explode("-",$row);
               echo "<tr>";
               foreach($emp as $val){
                    echo "<td>".$val."</td>";
               }
               echo $row;
               echo '<td><a href="#">Show Details</a></td>';
               echo '<td><a href="#">Delete</a></td>';
               echo "</tr>";
            echo "</tbody>";
        }
        ?>
       
   
</body>

</html>