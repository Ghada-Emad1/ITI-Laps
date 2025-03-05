
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    $data=file('data.txt');
    if(isset($_GET["row"])){
        $index=$_GET['row'];
        echo "<p>$data[$index]</p>";
    }
    ?>
</body>
</html>