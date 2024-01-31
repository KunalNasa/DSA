#include <iostream>
using namespace std;
int solve(vector<int> &nums, int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return nums[0];
    }

    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1);

    return max(include, exclude);
}
int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return nums[0];
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    int include = solveMem(nums, n - 2, dp) + nums[n];
    int exclude = solveMem(nums, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}
int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n , 0);
    dp[0] = nums[0];

    for(int i = 1; i < n; i++)
    {
        
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
        
    }
    return dp[n - 1];
}
int solveOpt(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++)
    {
        
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int curr = max(include, exclude);

        prev2 = prev1;
        prev1 = curr;
        
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // int ans = solve(nums, n);
    // return ans;
    // vector<int> dp(n, -1);
    // int ans = solveMem(nums, n - 1, dp);
    // return ans;

    int ans = solveTab(nums);
    return ans;
}

int main()
{
    
    
}
