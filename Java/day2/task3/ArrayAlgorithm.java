class ArrayAlgorithm{
    public static void main(String args[]){
       int array[]={10,90,23,80,1,4,-2,-10,50};
       int min=min(array);
       int max=max(array);
       System.out.println("Minimum Number in array is "+min);
       System.out.println("Minimum Number in array is "+max);

       int arr[]={1,2,3,4,5,6,7,8};
       int res=BinarySearch(arr,7);
       if(res!=-1){
        System.out.println("Find 7 at index "+res);
       }else{
        System.out.println("Element Not Exist");
       }
    }

    public static int max(int[]array){
        long startTime=System.nanoTime();
        int max=array[0];
        for(int i=1;i<array.length;i++){
            if(array[i]>max){
                max=array[i];
            }
        }
        long endTime=System.nanoTime();
        long executionTime=endTime-startTime;
        System.out.println("Exection Time in max Fucntion: "+executionTime +" nanoSeconds");
        return max;
    }
    public static int min(int array[]){
        long startTime=System.nanoTime();
        int min=array[0];
        for(int i=0;i<array.length;i++){
            if(array[i]<min){
                min=array[i];
            }
        }
        long endTime=System.nanoTime();
        long executionTime=endTime-startTime;
        System.out.println("Exection Time in min function: "+executionTime +" nanoSeconds");
        
        return min;
    }

    public static int BinarySearch(int[] arr,int data){
        int start=0;
        int end=arr.length-1;
        while(start<=end){
            int mid=(start+end)/2;
           if(arr[mid]==data){
             return mid;
           }
           else if(arr[mid]>data){
            end=mid-1;
           }else{
            start=mid+1;
           }
        }
        return -1;
    }

}