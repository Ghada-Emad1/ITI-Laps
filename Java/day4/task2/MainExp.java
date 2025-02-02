package pkg2;
class MainExp{
    public static void main(String args[]){
       ThrowerException thw=new ThrowerException();

       try{
        thw.method1(-1);

       }catch(MyOwnException e){
        System.out.println("Catching Exception :" + e.getMessage());
       }finally{
        System.out.println("finally block for method1");
       }
      
       try{
        thw.method2();

       }catch(MyOwnException e){
        System.out.println("Catching Execption from mehtod2 "+e.getMessage());
       }finally{
        System.out.println("finally block of mehtod2");
       }

       try{
        thw.method3();

       }catch(MyOwnException e){
        System.out.println("Catching Exception from mehtod3" + e.getMessage());
       }finally{
        System.out.println("Finally block of method3");
       }
    }

  
}