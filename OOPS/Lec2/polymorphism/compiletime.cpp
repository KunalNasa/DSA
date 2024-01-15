#include<iostream>
using namespace std;
class A
{
    public:
    void sayhello()
    {
        cout << "Hello world" << endl;
    }
    int sayhello(string name, int n)
    {
        cout << "Hello" << name << endl;
        return n; 
    }
    void sayhello(string s)
    {
        cout << "Hello " << s << endl;
    }
};
int main()
{
    A obj;
    obj.sayhello("tinku");
}