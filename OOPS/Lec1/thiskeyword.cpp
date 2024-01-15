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
        cout <<"this -> " << this << endl;
        this -> health = health;
    }

    Hero(int health, char level)
    {
        cout <<"this -> " << this << endl;
        this -> level = level;
        this -> health = health;
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
    // static way 
    Hero ramesh(60);
    // cout << "Address of ramesh is " << &ramesh << endl;
    ramesh.gethealth();
    ramesh.print();

    // dynamic way 
    Hero *h = new Hero(70, 'A');
    h -> print();


}