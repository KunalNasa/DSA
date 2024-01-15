#include <iostream>
using namespace std;

int main()
{
    /*
    int n;
    cin>>n;
    cout<<"hello\n";
    */
    // int a = 3, b =4;
    // if(a>b)
    // {
    //     cout<<"a is greater than b \n";
    // }
    // else{
    //     cout<<"b is greater than a\n";
    // }
    /*
    int a,b;
    cout<<"Enter the value of a \n";
    cin >>a;
    cout<<"Enter the value of b \n";
    cin>>b;
    if(a>b)
    {
        cout<<"a is greater than b \n";
    }
    else if (a<b)
    {
        cout<<"b is grater than a \n";
    }
    else
    {
        cout<<"a and b are equal\n";
    }
    */
    char ch;
    cout << "Enter your character \n";
    cin >> ch;
    if (ch >= 'a' && ch <= 'z')
    {
        cout << "Your character is in lowercase\n";
    }
    else if (ch>='A' && ch <='Z')
    {
        cout << "Your character is in uppercase\n";
    }
    else if('0'<=ch && ch<='9')
    {
        cout << "You have entered a digit\n";
    }
    else{
        cout<<"You have not entered any uppercase, lowercase or digit \n";
    }

}
