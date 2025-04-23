#include <iostream>

using namespace std;
class Stack{
    int tos;
    int size;
    int *arr;
public:
    Stack(int _size=5){
        tos=-1;
        size=_size;
        arr=new int[size];
    }
    int isEmpty(){
        return tos==-1;
    }
    int isFull(){
        return tos==size-1;
    }
    void push(int data){
        if(tos<size-1){
            tos++;
            arr[tos]=data;
        }else{
            cout<<"Stack is Full";
        }
    }
    int pop(){
        if(!isEmpty()){
        return arr[tos--];
        }else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

    }
    int top(){
        if(!isEmpty())return arr[tos];
        else{
            return -1;
        }
    }
};
int ExecuteOperation(char op,int num1,int num2){
    int res=0;
    if(op=='+') res=num1+num2;
    if(op=='-') res=num1-num2;
    if(op=='*') res=num1*num2;
    if(op=='/') res=num1/num2;
    return res;
}

int Precedence(char p){
    if(p=='*'||p=='/')return 2;
    if(p=='+'||p=='-')return 1;
    return 0;
}
int isNumbericDigigt(char C){
    if(C>='0'&&C<='9')return 1;
    return 0;
}
int EvaluteEquation(char*arr){
    Stack Num_Stack(100);
    Stack char_Stack(100);
    for(int i=0;arr[i]!='\0';i++){
        if(isNumbericDigigt(arr[i])){
            Num_Stack.push(arr[i]-'0');
        }
        else{
                while (!char_Stack.isEmpty() && Precedence(char_Stack.top()) >= Precedence(arr[i])) {
                int val1 = Num_Stack.pop();
                int val2 = Num_Stack.pop();
                char op = char_Stack.pop();
                Num_Stack.push(ExecuteOperation(op, val2, val1));
            }
            char_Stack.push(arr[i]);
        }
    }
    while (!char_Stack.isEmpty()) {
        int val1 = Num_Stack.pop();
        int val2 = Num_Stack.pop();
        char op = char_Stack.pop();
        Num_Stack.push(ExecuteOperation(op, val2, val1));
    }

    return Num_Stack.pop();

}

int main()
{

   char arr[100];
   cout<<"Enter Your Equation : ";
   cin>>arr;
   cout<<"Result is : "<<EvaluteEquation(arr);

}
