#include <iostream>
#define MOD 1000000007
using namespace std;
long long int solve(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }

    long long int ans = (n - 1) * (solve(n - 1) + solve(n - 2));
    return ans % 1000000007;
}

long long int solveMem(int n, vector<long long int> &dp)
{
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    if(dp[n] != -1)
        return dp[n] % 1000000007;

    dp[n] = (n - 1) * (solveMem(n - 1, dp) + solveMem(n - 2, dp));
    return dp[n] % 1000000007;
}
long long int solveTab(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;
        
        dp[i] = ans;
    }
    return dp[n] % MOD;
}
long long int solveSO(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3; i <= n; i++)
    {
        int curr = (((i-1) % MOD) * ((prev1 % MOD) + (prev2 % MOD)) % MOD);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, -1);
    long long int ans = solve(n);
    return ans;
}
int main()
{

}
