package pkg2;
public class ThrowerException{
    public void method1(int value) throws MyOwnException{
        if (value<0){
            throw new MyOwnException("value can't be negative");
        }else{
            System.out.println("Execute sucessfully without exception");
        }
    }
    public void method2() throws MyOwnException{
        throw new MyOwnException("Execption from method2");
    }
    public void method3() throws MyOwnException{
        throw new MyOwnException("Execption from method3");
    }
}