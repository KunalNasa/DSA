#include<iostream>
using namespace std;
int modularExponentiation(int x, int n)
{
    //we have to calculate (x^n)%m, (^ ---> power)
    int result = 1;
    while (n>0)
    {
        if (n&1)
        {//odd
            result = result * x;
        }
        x = x*x;
        n = n>>1; // = divide by 2
    }
    return result;
}
int main()
{
    cout<<modularExponentiation(2,3)<<endl;   
}