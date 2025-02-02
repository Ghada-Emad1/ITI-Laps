package pkg3;
import java.util.ArrayList;
class MainShapeTest{
    public static void main(String args[]){
        
        ArrayList<Rectangle> rect=new ArrayList<>();
        rect.add(new Rectangle());
        rect.add(new Rectangle());

        ArrayList<Circle>circle=new ArrayList<>();
        circle.add(new Circle());

        TestClass testclass=new TestClass();
        System.out.println("Draw the rectangle");
        testclass.TestShape(rect);

        System.out.println("Draw the circle");
        testclass.TestShape(circle);

    }
}