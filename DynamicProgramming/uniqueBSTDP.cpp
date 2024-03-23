#include <iostream>
using namespace std;
class Solution {
public:
    int solve(int n)
    {
        if(n <= 1)
        {
            return 1;
        }
        int ans = 0;
        // think i as root Nodes
        for(int i = 1; i <= n; i++)
        {
            ans += solve(i - 1) * solve(n - i);
        }
        return ans;
    }
    int solveMem(int n, vector<int> &dp)
    {
        if(n <= 1)
        {
            return 1;
        }
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        // think i as root Nodes
        for(int i = 1; i <= n; i++)
        {
            ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
        }
        return dp[n] = ans;
    }
    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            // i -> no of nodes
            for(int j = 1; j <= i; j++)
            {
                // j -> root node
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    unsigned long long  fac(int n)
    {
        if(n == 1 || n == 0)
        {
            return 1;
        }
        return n * fac(n - 1);
    }
    int catalan(int n)
    {
        long long int ans = fac(2*n) / (fac(n + 1) * fac(n));
        return ans;
    }
    
    int numTrees(int n) {
        // if(n <= 1)
        // {
        //     return 1;
        // }
        // int ans = 0;
        // // think i as root Nodes
        // for(int i = 1; i <= n; i++)
        // {
        //     ans += numTrees(i - 1) * numTrees(n - i);
        // }
        // return ans;
        vector<int> dp(n + 1, -1);
        // return solve(n);
        // return solveMem(n, dp);
        // return solveTab(n);
        return catalan(n);



    }
};

int main()
{
    
    
}
