#include<iostream>
using namespace std;
class A
{
    public:
    int a;
    int b;

    public:
    int add()
    {
        return a + b;
    }
    void operator+ (A &obj)
    {
        // int value1 = this -> a;
        // int value2 = obj.a;
        // cout << "output = " << value2 - value1 << endl;

        cout << "Hello" << endl;
    }

    void operator() ()
    {
        cout << " Bracket overloaded " << this -> a << endl;
    }
};
using namespace std;
int main()
{
    A obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;

    obj1();
}