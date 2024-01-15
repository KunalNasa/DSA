#include<iostream>
using namespace std;
int isprime(int n)
{
    int cnt = 0;
    vector <bool> prime(n+1, true); //0 se n tak numbers
    prime[0] = prime[1] = false; 
    for (int i = 2; i < n; i++)
    {
        if (prime[i]) //starting me every number prime hai
        {
            cnt++;
            for (int j = 2 * i; j < n; j = j + i) //phle prime number ki table ke saare
            // number non-prime declare kardo
            {
                prime[j] = false; 
            }   
        }   
    }
    return cnt;
}
int optimisePrime(int n)
{
    vector <bool> optPrime(n+1, true);
    optPrime[0] = optPrime[1] = 0;
    int count = 0;
    for (int i = 2; i*i < n; i++)
    {
        if(optPrime[i])
        {
            for (int j = i*i; j < n; j = j + i)
            {
                optPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (optPrime[i])
        {
            count++;
        }   
    }
    return count;
}
int main()
{
    cout<<isprime(10)<<endl;
    cout<<optimisePrime(10)<<endl;
}