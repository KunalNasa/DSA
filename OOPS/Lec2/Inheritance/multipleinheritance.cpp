#include<iostream>
using namespace std;
class animal
{
    public:
    int age;
    int weight;

    public:
    void bark()
    {
        cout << "Barking " << endl;

    }
};

class human
{
    public:
    string color;


    public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};
class hybrid : public animal, public human
{

};
int main()
{
    hybrid obj1;
    obj1.speak();
    obj1.bark();   
}