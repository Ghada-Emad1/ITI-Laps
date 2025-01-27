class PrintLines{
    public static void main (String args[]){
       int size=Integer.parseInt(args[0]);
       if(args.length==0){
        System.out.println("Enter valid number of args");
       }
       for(int i=0;i<size;i++){
         System.out.println(args[1]);
       }
      }
   }
