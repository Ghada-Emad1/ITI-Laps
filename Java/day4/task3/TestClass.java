package pkg3;
import java.util.ArrayList;
public class TestClass{
    public static void TestShape(ArrayList<?extends Shape> test){
        for(int i=0;i<test.size();i++){
            test.get(i).Draw();
        }
    }
}