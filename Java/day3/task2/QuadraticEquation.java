package pkg2;
import java.io.*;
public class QuadraticEquation{
     public static void main(String[] args) {
        double a=4;
		double b=3;
		double c=5;
		System.out.println("the the roots of the quadratic equation = "+ new FormulaSolution().apply(new double[]{a, b, c}));
    }
}