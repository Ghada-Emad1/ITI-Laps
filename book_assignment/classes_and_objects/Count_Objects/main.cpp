#include <iostream>

using namespace std;
class Counter{
    static int cnt;
public:
    Counter(){
        cnt++;
    }
    static void DisplayCount(){
        cout<<"I am object number "<<cnt;
    }
    ~Counter(){
        cnt--;
    }
};
int Counter::cnt=0;
int main()
{
    Counter c1;
    Counter c2;
    c2.DisplayCount();
    return 0;
}
