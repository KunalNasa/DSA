#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    // ------BINARY TO DECIMAL CONVERSION------
    /*
    int number;
    cout<<"enter your binary number\n";
    cin>>number;
    int i = 0, decimal = 0;
    while(number != 0)
    {
        decimal += number%10 * pow(2,i);
        number = number/10;
        i++;
    }
    cout<<decimal<<endl;
    */
   int decnumber;
   cout<<"Enter your decimal number\n";
   cin>>decnumber;
   int i = 1, binary = 0;
   while(decnumber != 0)
   {
    binary += (decnumber%2) * i;
    i = i*10;
    decnumber = decnumber/2;
   }
   cout<<binary<<endl;
}