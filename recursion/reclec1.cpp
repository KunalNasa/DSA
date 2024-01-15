#include<iostream>
using namespace std;
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
int powerof2(int n)
{
    // base case
    if(n == 0)
    {
        return 1;
    }
    else 
    {
        return 2 * powerof2(n-1);
    }
}
void reversecounting(int n)
{
    //Tail recursion
    //base case
    if(n == 0)
    {
        return ;
    }
    else
    {
        // process
        cout << n << " ";

        // Recursive relation
        reversecounting(n-1);  
    } 
}
void counting(int n)
{
    //Head recursion
    if(n == 0)
    {
        return ;
    }
        counting(n-1);
        cout << n << " ";
    
}
int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;

    int solution = powerof2(n);
    cout << solution << endl;

    counting(n);
    cout<<endl;

    reversecounting(n);
    cout<< endl;
}