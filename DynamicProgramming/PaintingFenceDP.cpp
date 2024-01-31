#include <iostream>
using namespace std;
#define MOD 1000000007
int sum(int a, int b)
{
    return(a % MOD + b % MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a%MOD)* 1LL * (b%MOD)) % MOD;
}
int solve(int n, int k)
{
    if(n == 2)
    {
        return sum(k, mul(k,(k-1)));
    }
    if(n == 1)
    {
        return k;
    }

    int ans = sum(mul(solve(n-2, k), k - 1), mul(solve(n -1, k), k - 1));
    return ans % MOD;
}
int solveMem(int n, int k, vector<int> &dp)
{
    if(n == 2)
    {
        return sum(k, mul(k,(k-1)));
    }
    if(n == 1)
    {
        return k % MOD;
    }
    if(dp[n] != -1)
        return dp[n] % MOD;

    dp[n] = sum(mul(solveMem(n-2, k, dp), k - 1), mul(solveMem(n -1, k, dp), k - 1));

    return dp[n] % MOD;
}
int solveTab(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = sum(k, mul(k,(k-1)));

    for(int i = 3; i <= n; i++)
    {
        dp[i] = sum(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}
int sovleSO(int n, int k)
{
    int prev2 = k;
    int prev1 = sum(k, mul(k,(k-1)));

    for(int i = 3; i <= n; i++)
    {
        int curr = sum(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
    if(n == 1)
    {
        return 1;
    }
    vector<int> dp(n + 1, -1);
    int ans = solveMem(n, k, dp);
    // return ans;
    return solveTab(n, k);
}

int main()
{
    
}
