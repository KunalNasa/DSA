#include<iostream>
#include <bits/stdc++.h>
using namespace std;
    int solve(vector<int>& obstacles,int currlane, int currpos)
    {
        int n = obstacles.size();
        if(currpos == n - 1)
        {
            return 0;
        }
        
        if(obstacles[currpos + 1] != currlane)
        {
             return solve(obstacles, currlane, currpos + 1);
        }
        else
        {
            // sideways jump
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++)
            {
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
            }
            return ans;
        }
    }
    int solveMem(vector<int>& obstacles,int currlane, int currpos, vector<vector<int>> &dp)
    {
        int n = obstacles.size();
        if(currpos == n - 1)
        {
            return 0;
        }

        if(dp[currlane][currpos] != -1)
            return dp[currlane][currpos];
        
        if(obstacles[currpos + 1] != currlane)
        {
            return solveMem(obstacles, currlane, currpos + 1,dp);
        }
        else
        {
            // sideways jump
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++)
            {
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + solveMem(obstacles, i, currpos, dp));
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int solveTab(vector<int>& obstacles)
    {
        int n = obstacles.size() - 1;
         vector<vector<int>> dp(4, vector<int> (obstacles.size() , 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int pos = n - 1; pos >= 0; pos--)
        {
            for(int lane = 1; lane <= 3; lane++)
            {
                if(obstacles[pos + 1] != lane)
                {
                    dp[lane][pos] = dp[lane][pos + 1];
                }
                else
                {
                    // sideways jump
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++)
                    {
                        if(lane != i && obstacles[pos] != i)
                        ans = min(ans, 1 + dp[i][pos + 1]);
                    }
                    dp[lane][pos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
     int solveSO(vector<int>& obstacles)
    {
        int n = obstacles.size() - 1;
         vector<int> curr(4, 1e9);
         vector<int> next(4, 0);

        for(int pos = n - 1; pos >= 0; pos--)
        {
            for(int lane = 1; lane <= 3; lane++)
            {
                if(obstacles[pos + 1] != lane)
                {
                    curr[lane] = next[lane];
                }
                else
                {
                    // sideways jump
                    int ans = 1e9;
                    for(int i = 1; i <= 3; i++)
                    {
                        if(lane != i && obstacles[pos] != i)
                        ans = min(ans, 1 + next[i]);
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(next[1] + 1, next[3] + 1));
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int> (n, -1));
        // return solve(obstacles, 2, 0);
        // return solveMem(obstacles, 2, 0, dp);
        // return solveTab(obstacles);
        return solveSO(obstacles);

    }

int main()
{

}