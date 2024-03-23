#include <iostream>
using namespace std;
class Solution {
public:
    bool solve(string &s, string &p, int i, int j)
    {
        if(i < 0 && j < 0)
            return true;
        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
            {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(i >= 0 && j < 0)
            return false;
        
        if(s[i] == p[j] || p[j] == '?')
        {
            return solve(s, p, i - 1, j - 1);
        }
        else if(p[j] == '*')
        {
            return (solve(s, p, i - 1, j) || solve(s, p, i, j - 1));
        }
        else
        {
            return false;
        }

    }
    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return true;
        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
            {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(i >= 0 && j < 0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = solveMem(s, p, i - 1, j - 1, dp);
        }
        else if(p[j] == '*')
        {
            return dp[i][j] = (solveMem(s, p, i - 1, j, dp) || 
            solveMem(s, p, i, j - 1, dp));
        }
        else
        {
            return false;
        }

    }
    bool solveTab(string s, string p)
    {
        int n = s.length() - 1, m = p.length() - 1;
        vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= m + 1; j++)
        {
            bool flag = true;
            for(int k = 1; k <= j; k++)
            {
                if(p[k - 1] != '*')
                    flag = false;
                    break;
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i <= n + 1; i++)
        {
            for(int j = 1; j <= m + 1; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i-1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = (dp[i-1][j] || dp[i][j - 1]);
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n + 1][m + 1];
    }
    bool solveSO(string &s, string &p)
    {
        int n = s.length(), m = p.length();
        // vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        prev[0] = true;
        for(int j = 1; j <= m; j++)
        {
            bool flag = true;
            for(int k = 1; k <= j; k++)
            {
                if(p[k - 1] != '*')
                    flag = false;

            }
            prev[j] = flag;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = (prev[j] || curr[j - 1]);
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
    bool isMatch(string s, string p) {
        int n = s.length() - 1, m = p.length() - 1;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(s, p, n, m);
        // return solveMem(s, p, n, m, dp);
        // return solveTab(s, p);
        return solveSO(s,p);
    }
};
int main()
{
    
    
}