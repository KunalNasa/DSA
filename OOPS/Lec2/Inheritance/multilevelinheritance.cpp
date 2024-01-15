#include<iostream>
using namespace std;
class animal
{
    public:
    int age;
    int weight;

    public:
    void speak()
    {
        cout << "Speaking " << endl;

    }
};

class dog : public animal
{

};

class breed : public dog
{

};
int main()
{
    breed german;
    german.speak();
    
}