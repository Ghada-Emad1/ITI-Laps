class OccurenceInString{
    public static void main(String args[]){
        String paragraph="Doing Lap2 in Core java java";
        String word="java";
        System.out.println(numberOfOccurence(paragraph,word));
        System.out.println(numberOfOccurence(paragraph,word));
    }


    public static int numberOfOccurence(String paragraph,String word){
        paragraph=paragraph.toLowerCase();
        word=word.toLowerCase();
        String[] res=paragraph.split(" ");
        int count=0;
        for(int i=0;i<res.length;i++){
            if(res[i].equals(word)){
                count++;
            }
        }
        return count;
    }

    public static int countOccurence(String paragraph,String word){
        paragraph=paragraph.toLowerCase();
        word=word.toLowerCase();
        int count=0;
        int index=0;
        while((paragraph.indexOf(word,index))!=-1){
            index=paragraph.indexOf(word,index);
            count++;
            index+=word.length();  
        }
        return count;
    }
}