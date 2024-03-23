#include <iostream>
using namespace std;
class Solution {
public:
    int solve(int i, int j, string text1, string text2)
    {
        if(i >= text1.length() || j >= text2.length())
            return 0;
        
        int ans = 0;
        if(text1[i] == text2[j])
        {
            ans =  1 + solve(i + 1, j + 1, text1, text2); 
        }
        else
        {
            ans =  max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
        }
        return ans;
    }
    int solveMem(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if(i >= text1.length() || j >= text2.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solveMem(i + 1, j + 1, text1, text2, dp); 
        }
        else
        {
            return dp[i][j] = max(solveMem(i + 1, j, text1, text2, dp), solveMem(i, j + 1, text1, text2, dp));
        }
    }
    int solveTab(string text1, string text2)
    {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = n - 1; i>= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if(text1[i] == text2[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveSO(string text1, string text2)
    {
        int n = text1.length(), m = text2.length();
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for(int i = n - 1; i>= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if(text1[i] == text2[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solve(0, 0, text1, text2);
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        // return solveMem(0, 0, text1, text2, dp);
        // return solveTab(text1, text2);
        return solveSO(text1, text2);
    }
};
int main()
{
    
    
}