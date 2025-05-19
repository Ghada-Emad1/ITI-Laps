<?php

$apiId = '6df664ef45ed360a0aa7d9366ba59b36';
$json = file_get_contents('city.list.json');
$allCities = json_decode($json, true);
$egyptCities = array_filter($allCities, function($city) {
    return $city['country'] === 'EG';
});
$egyptCities = array_values($egyptCities);
$weather = '';

if (isset($_GET['city']) && $_GET['city']) {
    $cityId = $_GET['city'];

    $url = "https://api.openweathermap.org/data/2.5/weather?id={$cityId}&appid={$apiId}&units=metric";

    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $response = curl_exec($ch);
    curl_close($ch);

    $result = json_decode($response, true);

    if (isset($result['main'])) {
        $cityName = $result['name'];
        $temp = $result['main']['temp'];
        $temp_min = $result['main']['temp_min'];  
        $temp_max = $result['main']['temp_max'];
        $des = $result['weather'][0]['description'];
        $humidity = $result['main']['humidity'];
        $wind_speed=$result['wind']['speed'];

        $weather = "
        <div>
            <h1>Weather in {$cityName}</h1>
            <p>Temperature: {$temp} °C</p>
            <p>Min Temperature: {$temp_min} °C</p>
            <p>Max Temperature: {$temp_max} °C</p>
            <p>Description: {$des}</p>
            <p>Humidity: {$humidity}%</p>
            <p>Wind speed {$wind_speed}</p>
        </div>";
    } else {
        $weather = "<p>Weather data not found.</p>";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Egypt Weather App</title>
</head>
<body>

<form method="get">
    <select name="city">
        <option value="">Select a City:</option>
        <?php foreach ($egyptCities as $city): ?>
            <option value="<?php echo $city['id'] ?>">
                <?php echo $city['name'] ?>
            </option>
        <?php endforeach; ?>
    </select>
    <input type="submit" value="Get Weather">
</form>

<?php echo $weather ?>

</body>
</html>
