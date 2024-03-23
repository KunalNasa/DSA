#include <iostream>
using namespace std;
class Solution {
public:
    int solve(int i, int j, string a, string b) {
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;

        int ans = 0;
        if (a[i] == b[j]) {
            return solve(i + 1, j + 1, a, b);
        } else {
            int insertAns = 1 + solve(i, j + 1, a, b);
            int deleteAns = 1 + solve(i + 1, j, a, b);
            int replaceAns = 1 + solve(i + 1, j + 1, a, b);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
    int solveMem(int i, int j, string a, string b, vector<vector<int>>& dp) {
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j]) {
            return solveMem(i + 1, j + 1, a, b, dp);
        } else {
            int insertAns = 1 + solveMem(i, j + 1, a, b, dp);
            int deleteAns = 1 + solveMem(i + 1, j, a, b, dp);
            int replaceAns = 1 + solveMem(i + 1, j + 1, a, b, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j < b.length(); j++) {
            dp[n][j] = m - j;
        }
        for (int i = 0; i < a.length(); i++) {
            dp[i][m] = n - i;
        }
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insertAns = 1 + dp[i][j + 1];
                    int deleteAns = 1 + dp[i + 1][j];
                    int replaceAns = 1 + dp[i + 1][j + 1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveSO(string a, string b) {
        int n = a.length(), m = b.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int j = 0; j < m; j++) {
            next[j] = m - j;
        }
        // for (int i = 0; i < n; i++) {
        //     curr[m] = n - i;
        // }
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--)
            {
                // catch here
                curr[m] = n - i;

                int ans = 0;
                if (a[i] == b[j]) {
                    ans = next[j + 1];
                } else {
                    int insertAns = 1 + curr[j + 1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j + 1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        // return solve(0, 0, word1, word2);
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveMem(0, 0, word1, word2, dp);
        // return solveTab(word1, word2);
        if(word2.length() == 0)
        {
            return n;
        }
        if(word1.length() == 0)
            return m;
        return solveSO(word1, word2);
    }
};
int main()
{
    
    
}