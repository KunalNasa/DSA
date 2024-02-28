#include<iostream>
using namespace std;

class Solution {
public:
    int solve(int index, int endIndex, vector<int> &slices, int n)
    {
        if(index > endIndex || n == 0)
            return 0;
        
        int include = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        int exclude = 0 + solve(index + 1, endIndex, slices, n);

        return max(include, exclude);
    }
    int solveMem(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if(index > endIndex || n == 0)
            return 0;
        
        if(dp[index][n] != -1)
        {
            return dp[index][n];
        }
        int include = slices[index] + solveMem(index + 2, endIndex, slices, n - 1, dp);
        int exclude = 0 + solveMem(index + 1, endIndex, slices, n, dp);

        dp[index][n] =  max(include, exclude);
        return dp[index][n];
    }
    int solveTab(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int> (k, 0));
        vector<vector<int>> dp2(k + 2, vector<int> (k, 0));

        for(int index = k - 2; index >= 0; index--)
        {
            for(int n = 1; n <= k / 3; n++)
            {
                int include = slices[index] + dp1[index + 2][n - 1];
                int exclude = 0 + dp1[index + 1][n];

                dp1[index][n] =  max(include, exclude);
            }
        }
        for(int index = k - 1; index >= 1; index--)
        {
            for(int n = 1; n <= k / 3; n++)
            {
                int include = slices[index] + dp2[index + 2][n - 1];
                int exclude = 0 + dp2[index + 1][n];

                dp2[index][n] =  max(include, exclude);
            }
        }
        return max(dp1[0][k/3], dp2[1][k/3]);

    }
    int solveSO(vector<int> &slices)
    {
        int k = slices.size();
        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        for(int index = k - 2; index >= 0; index--)
        {
            for(int n = 1; n <= k / 3; n++)
            {
                int include = slices[index] + next1[n - 1];
                int exclude = 0 + curr1[n];

                prev1[n] =  max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        for(int index = k - 1; index >= 1; index--)
        {
            for(int n = 1; n <= k / 3; n++)
            {
                int include = slices[index] + next2[n - 1];
                int exclude = 0 + curr2[n];

                prev2[n] =  max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;

        }
        return max(curr1[k/3], curr2[k/3]);

    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int> > dp1(k, vector<int> (k, -1));
        vector<vector<int> > dp2(k, vector<int> (k, -1));

        // int ans1 = solve(0, k - 2, slices, k / 3);
        // int ans2 = solve(1, k - 1, slices, k / 3);

        // int ans1 = solveMem(0, k - 2, slices, k / 3, dp1);
        // int ans2 = solveMem(1, k - 1, slices, k / 3, dp2);

        // return max(ans1, ans2);

        // return solveTab(slices);
        return solveSO(slices);

        
    }
};
int main()
{
    
}