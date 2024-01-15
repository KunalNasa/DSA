#include<iostream>
using namespace std;

class Hero
{
    public:
    int health;
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
        cout <<"this -> " << this << endl;
        this -> health = health;
    }

    Hero(int health, char level)
    {
        cout <<"this -> " << this << endl;
        this -> level = level;
        this -> health = health;
    }

    // Copy Constructor
     Hero(Hero &temp)
     {
        cout << "Copy constructor called " << endl;
        this -> level = temp.level;
        this -> health = temp.health;

     }

    void print()
    {
        cout << health << endl;
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
   Hero suresh(70, 'C');
   suresh.print();

   // Copy constructor
   Hero ritesh(suresh);
   ritesh.print();

}