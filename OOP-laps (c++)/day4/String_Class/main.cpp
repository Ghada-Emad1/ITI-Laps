#include <iostream>
#include<string.h>
using namespace std;
class String
{
    int size;
    char *arr;
public:
    String()
    {
        size=10;
        arr=new char[size];
        arr[0]='\0';
    }
    String(int _size)
    {
        size=_size;
        arr=new char[size];
        arr[0]='\0';
    }
    String (const String &s)
    {
        size=s.size;
        arr=new char[size];
        for(int i=0; i<size; i++)
        {
            arr[i]=s.arr[i];
        }
    }
    String(char *_arr)
    {
        size=length(_arr)+1+10;
        arr=new char[size];
        strcpy(arr,_arr);

    }
    void setName(char *_arr)
    {
        delete []arr;
        size=length(_arr)+1;
        arr=new char[size];
        strcpy(arr,_arr);
    }
    int getSize()
    {
        return size;
    }
    char* getName()
    {
        return arr;
    }
    int length(char *_Name)
    {
        int i=0,cnt=0;
        while(_Name[i]!='\0')
        {
            cnt++;
            i++;
        }
        return cnt;
    }
    String operator =(const String &s)
    {
        delete []arr;
        size=s.size;
        arr=new char[size];
        strcpy(arr,s.arr);
        return *this;
    }
    String operator +(const String s)
    {

        String s3;
        strcat(arr,s.arr);
        strcat(s3.arr,arr);


        return s3;

    }
    void print()
    {
        if(arr[0]=='\0')
        {
            cout<<"Size : "<<getSize()<<endl;
        }
        else
        {
            cout << "Size: " << getSize() << ", String: " << getName() << endl;

        }

    }
    ~String()
    {
        delete []arr;
        cout<<"object removed"<<endl;
    }
};
int main()
{
    String s;
    s.print();
    String s2(30);
    s2.print();
    String s3("ahmed");
    s3.print();
    String s4;
    s4.setName("ghada");
    s4.print();
    String s5("gehad");
    String s6;
    s6=s5;
    s6.print();


    String s7("alaa");
    String s8("sara");
    String s9=s7+s8;
    s9.print();
    return 0;
}
