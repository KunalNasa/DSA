#include<iostream>
using namespace std;
class human
{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge()
    {
        return this -> age;
    }
    void setWeight(int w)
    {
        this -> weight = w;
    }
};

class male: public human
{
    public:
    string color;

    void sleeping()
    {
        cout << "yuva abhi tak so rha hai" << endl;
    }
};

// class male: protected human
// {
//     public:
//     string color;

//     void sleeping()
//     {
//         cout << "yuva abhi tak so rha hai" << endl;
//     }
// };
int main()
{
    male object1;
    object1.setWeight(69);
    object1.age = 20;
    object1.color = "fair";
    cout<< object1.age << endl; 
    cout<< object1.color << endl;   
    cout<< object1.weight << endl;   
    object1.sleeping();


}