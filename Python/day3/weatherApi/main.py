import requests
from dotenv import load_dotenv
import os
load_dotenv()  
class Weather:
    Weather_URL = "http://api.weatherapi.com/v1"

    def __init__(self, api_key):
        self.api_key = api_key

    def get_current_temperature(self, city):
        print(self.api_key)
        url = f"{Weather.Weather_URL}/current.json?key={self.api_key}&q={city}&api=no"
        response = requests.get(url)
        data = response.json()
        if "error" in data:
            print(f"Error: {data['error']['message']}")
            return
        current_temperature_celis = data["current"]["temp_c"]
        current_temperature_fran = data["current"]["temp_f"]
        print(
            f"Temperature in celis {current_temperature_celis} and in franheit {current_temperature_fran}"
        )

    def get_temperature_after(self, city, days, hour=None):
        url = f"{Weather.Weather_URL}/forecast.json?key={self.api_key}&q={city}&days={days}&aqi=no&alerts=no"
        response = requests.get(url)
        data = response.json()
        if "error" in data:
            print(f"Error: {data['error']['message']}")
            return
        try:
            date = data["forecast"]["forecastday"][days - 1]["date"]
            if hour is not None:
                temperature_celis = data["forecast"]["forecastday"][days - 1]["hour"][
                    hour
                ]["temp_c"]
                temperature_franheit = data["forecast"]["forecastday"][days - 1][
                    "hour"
                ][hour]["temp_f"]
                print(
                    f"in{date}  {hour} Temperature in celis will be {temperature_celis} and in franheit will be{temperature_franheit}"
                )
            else:
                temperature_celis = data["forecast"]["forecastday"][days - 1]["day"][
                    "avgtemp_c"
                ]
                temperature_franheit = data["forecast"]["forecastday"][days - 1]["day"][
                    "avgtemp_f"
                ]
                print(
                    f" in {date} Temperature in celis  will be {temperature_celis} and in franheit will be{temperature_franheit}"
                )

        except IndexError:
            print(f"Error: Invalid day or hour index")
            return

    def get_lat_and_long(self, city):
        url = f"{Weather.Weather_URL}/current.json?key={self.api_key}&q={city}&api=no"
        response = requests.get(url)
        data = response.json()
        if "error" in data:
            print(f"Error: {data['error']['message']}")
            return
        latitude=data['location']['lat']
        longitude=data['location']['lon']
        print(f'in {city} Latitude is {latitude} and Longitude is {longitude}')


api_key = os.getenv("WEATHER_KEY")
print(api_key)

w = Weather(api_key=api_key)
w.get_current_temperature('egypt')
w.get_temperature_after("egypt", 2)
w.get_lat_and_long("egypt")
