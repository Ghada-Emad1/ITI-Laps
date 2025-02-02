package pkg4;
public class ComplexTest {
    public static void main(String[] args) {
        DoubleComplex c1 = new DoubleComplex(3.0, 2.0);
        DoubleComplex c2 = new DoubleComplex(1.0, 4.0);
        System.out.println("c1 = " + c1);
        System.out.println("c2 = " + c2);
        System.out.println("Addition: " + c1.add(c2));
        System.out.println("Subtraction: " + c1.subtract(c2));
        System.out.println("Multiplication: " + c1.product(c2));
        System.out.println("Division: " + c1.div(c2));
    }
}
