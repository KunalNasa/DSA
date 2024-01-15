#include<iostream>
// #include "Hero.cpp"
using namespace std;
// class Hero
// {
//     public: // kahi bhi access kar sakte hai
//     int health;
//     // public: // upper vaala public hai or niche vala ab private hogaya
//     private: //level private hogaya
//     char level;

//     void print()
//     {
//         cout << level << endl; // no error 
//     }
// };

class Hero
{
    private:
    int health;

    public:
    char level;

    void print()
    {
        cout << level << endl;
    }

    // getter and setter to access private variable
    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }

    void sethealth(int h) //, char name)
    {
        // if(name == 'A')
        // {
        //      health = h;
        // }
         health = h;
       
    }

    void setlevel(char ch)
    {
        level = ch;
    }

};
int main()
{
    // Hero Bheem;
    // cout << "Bheem health is : " << Bheem.gethealth() << endl;
    // // Bheem.health = 90;
    // Bheem.level = 'A';

    // // use setter 
    // Bheem.sethealth(80);
    // Bheem.setlevel('A');
    // cout<< "size : " << sizeof(Hero) << endl;
    // cout << "Health is : " << Bheem.gethealth() << endl;
    // cout << "Level is : " << Bheem.level << endl;

    // cout << "Size of Bheem : " << sizeof(Bheem) << endl;
}