package pkg1;
import java.io.*;

public class Temperature{ 
    public static void main(String[] args) {
        float x = 24;
        System.out.println("Temperature  "+x+"C in Fahrenheit is "+new TemperatureConverter().apply(x) + "F");
    }
}
