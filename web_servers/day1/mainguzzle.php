<?php
require './vendor/autoload.php';

$apiId = '6df664ef45ed360a0aa7d9366ba59b36';
$json = file_get_contents('city.list.json');
$allCities = json_decode($json, true);

// Filter Egypt cities
$egyptCities = array_values(array_filter($allCities, function ($city) {
    return $city['country'] === 'EG';
}));

$weather = '';
$url = "https://api.openweathermap.org/data/2.5/weather";

$client = new GuzzleHttp\Client();

if (isset($_GET['city']) && $_GET['city']) {
    $cityId = $_GET['city'];

  
        $response = $client->get($url, [
            'query' => [
                'id' => $cityId,
                'appid' => $apiId,
                'units' => 'metric',
            ],
        ]);

        $data = json_decode($response->getBody(), true);
        echo $data['main'];
        if (isset($data['main'])) {
            $cityName = $data['name'];
            $temp = $data['main']['temp'];
            $temp_min = $data['main']['temp_min'];
            $temp_max = $data['main']['temp_max'];
            $des = $data['weather'][0]['description'];
            $humidity = $data['main']['humidity'];
            $wind_speed=$result['wind']['speed'];

            $weather = "<div>
                <h1>Weather in {$cityName}</h1>
                <p>Temperature: {$temp}°C</p>
                <p>Min Temperature: {$temp_min}°C</p>
                <p>Max Temperature: {$temp_max}°C</p>
                <p>Description: {$des}</p>
                <p>Humidity: {$humidity}%</p>
            </div>";
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
    <label for="city">Select a City:</label>
    <select name="city" id="city">
        <?php foreach ($egyptCities as $city): ?>
            <option value="<?php echo $city['id'] ?>" >
                <?php echo $city['name'] ?>
            </option>
        <?php endforeach; ?>
    </select>
    <input type="submit" value="Get Weather">
</form>

<?php echo $weather ?>

</body>
</html>
