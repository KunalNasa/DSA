#include<iostream>
using namespace std;

class Hero
{
    private:
    int health;

    public:
    char level;

    Hero()
    // ye constructor create karne ke baad jo default constructor compiler ne create kiya tha vo delete
    // ho chuka hai.
    {
        cout << "Constructor called" << endl;
    }

    //parameterized constructor
    Hero(int health)
    {
        health = health;
    }
    void print()
    {
        cout << level << endl;
    }

    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
         health = h;
       
    }

    void setlevel(char ch)
    {
        level = ch;
    }
 
};
int main()
{
    // cout << "Hi" << endl;
    // Hero ramesh;
    // cout << "Hello" << endl;

    // Dynamically
    Hero * h = new Hero();




    // // statically allocated
    // Hero a; 
    // a.sethealth(40);
    // a.setlevel('A');
    // cout << "Level is : " << a.level << endl;
    // cout << "Health is : " << a.gethealth() << endl;
    // // Dynamic allocation 
    // Hero *b = new Hero;
    // // cout << (*b).level << endl; 
    // b->sethealth(60);
    // b->setlevel('B');
    // cout << "Level is : " << b->level << endl;
    // cout << "Health is : " << (*b).gethealth() << endl;

}