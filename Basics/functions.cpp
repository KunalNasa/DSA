#include<iostream>
using namespace std;
int power(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans*a;
    }
    return ans;
}
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}
int fibonacci(int n)
{
    if(n == 1 || n == 2 )
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main()
{
    // int a,b;
    // cout<<"enter two numbers: ";
    // cin>>a>>b;
    // cout<<power(a,b)<<endl;
    int n,r;
    cout<<"Enter n and r respectively: ";
    // cin>>n>>r;
    n = 4;
    int ans = factorial(n)/factorial(r)/factorial(n-r);
    cout<<ans<<endl;
    cout<<fibonacci(6)<<endl;

}