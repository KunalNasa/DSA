#include <iostream>
using namespace std;
int fibonacci(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if(num == 1)
    {
        return 1;
    }
    return fibonacci(num - 2) + fibonacci(num - 1);
}
int main()
{
    int number;
    cin >> number;
    cout << fibonacci(number) << endl;
    int a = 0;
    int b = 1;
    int temp;
    int ans = a + b;
    if(number == 0)
    {
        ans = 0;
    }
    if(number == 1)
    {
        ans = 1;
    }
    for (int i = 2; i < number; i++)
    {
       temp = a;
       a = b;
       b = temp + b;
       ans = a + b;
    }
    cout<<ans<<endl;
    
}