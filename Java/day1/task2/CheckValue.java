class CheckValue{
   public static void main (String args[]){
      String value="CoreJava";
      if(args.length==0 || args.length==1){
        System.out.println("Enter vaild number of args");
      }
      if(value.equals(args[0])){
        System.out.println("true value "+args[0]);
      }else{
        System.out.println("false value please try again");
      }
   }
}
