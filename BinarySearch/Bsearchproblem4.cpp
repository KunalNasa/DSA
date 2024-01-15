#include <iostream>
using namespace std;
long long int sqroot(int n)
{
    int s = 0, e = n - 1;
    long long int ans;
    long long int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double precise(int tempsol , int precision, int number)
{
    double factor = 1;
    double finalsol = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor/10;
        for (double j = finalsol; j*j < number ; j = j + factor)
        {
            finalsol = j;
        }
    }
    return finalsol;
}
int main()
{
    int n;
    float ans;
    cout << "Enter number";
    cin >> n;
    int tempsol = sqroot(n);
    float finalsolution = precise(tempsol,3,n);
    cout<<finalsolution<<endl;
}  