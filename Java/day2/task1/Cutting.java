import java.util.StringTokenizer;
class Cutting{
    public static void main(String args[]){
        if(args.length==0){
           System.out.println("Please Enter An Ip");
           retrun;
        }
        String[]res=IpCutter(args[0]);
        for(int i=0;i<res.length;i++){
            System.out.println(Integer.parseInt(res[i]));
        }

        StringTokenizer res1=DoIpSplit(args[0]);
        while(res1.hasMoreTokens()){
            System.out.println(res1.nextToken());
        }

    }

    public static String[]IpCutter(String Ip){
        String[] myarr=Ip.split("\\.");
        return myarr;
    } 
    
    public static StringTokenizer DoIpSplit(String Ip){
         StringTokenizer str = new StringTokenizer(Ip, ".");
        return str;
    }
}