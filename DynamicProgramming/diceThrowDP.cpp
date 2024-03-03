#include <iostream>
using namespace std;
long long solve(int faces, int dice, int target)
  {
      if(target < 0)
      {
          return 0;
      }
      if(dice == 0 && target != 0)
      {
          return 0;
      }
      if(target == 0 && dice != 0)
      {
          return 0;
      }
      if(dice == 0 && target == 0)
      {
          return 1;
      }
      
      long long ans = 0;
      for(int i = 1; i <= faces; i++)
      {
          ans += solve(faces, dice - 1, target - i);
      }
      return ans;
  }
  long long solveMem(int faces, int dice, int target, vector<vector<long long >> &dp)
  {
      if(target < 0)
      {
          return 0;
      }
      if(dice == 0 && target != 0)
      {
          return 0;
      }
      if(target == 0 && dice != 0)
      {
          return 0;
      }
      if(dice == 0 && target == 0)
      {
          return 1;
      }
      if(dp[dice][target] != -1)
      {
          return dp[dice][target];
      }
      
      long long ans = 0;
      for(int i = 1; i <= faces; i++)
      {
          ans += solveMem(faces, dice - 1, target - i, dp);
      }
      dp[dice][target] = ans;
      return dp[dice][target];
  }
  
  long long solveTab(int faces, int dice, int target)
  {
      vector<vector<long long>> dp(dice + 1, vector<long long> (target + 1, 0));
      dp[0][0] = 1;
      
       
      for(int i = 1; i <= dice; i++)
      {
          for(int j = 1; j <= target; j++)
            {
                long long ans = 0;
                for(int k = 1; k <= faces; k++)
                {
                    if(j - k >= 0)
                        ans += dp[i - 1][j - k];
                }
                dp[i][j] = ans;
            }
      }
      return dp[dice][target];
      
  }
  long long solveSO(int faces, int dice, int target)
  {
      vector<long long> curr(target + 1, 0);
      vector<long long> prev(target + 1, 0);
      prev[0] = 1;
      
       
      for(int i = 1; i <= dice; i++)
      {
          for(int j = 1; j <= target; j++)
            {
                long long ans = 0;
                for(int k = 1; k <= faces; k++)
                {
                    if(j - k >= 0)
                        ans += prev[j - k];
                }
                curr[j] = ans;
            }
            prev = curr;
      }
      return prev[target];
      
  }
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long >> dp(N + 1, vector<long long > (X+ 1, -1));
        // return solve(M, N, X);
        // return solveMem(M, N, X, dp);
        // return solveTab(M, N, X);
        return solveSO(M, N, X);
    }
int main()
{
    
    
}