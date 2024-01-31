#include <iostream>
using namespace std;
 
int solve(vector<int> &num, int x)
{
    if(x < 0)
    {
        return INT_MAX;
    }
    if(x == 0)
    {
        return 0;
    }
    int mini = INT_MAX;
    for(int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, x - num[i]);
        if(ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}
int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    if(x < 0)
    {
        return INT_MAX;
    }
    if(x == 0)
    {
        return 0;
    }
    // step 3
    if(dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i = 0; i < num.size(); i++)
    {
        int ans = solveMem(num, x - num[i], dp);
        if(ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    // step 2
    dp[x] = mini;

    return mini;
}
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; i++)
    {
        // for each value of dp[i]
        for(int j = 0; j < num.size(); j++)
        {
            if(i -  num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX)
    {
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // int ans = solve(num, x);
    // if(ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;

    // step 1
    // vector<int> dp(x + 1, -1); // x + 1 : because after each iteration in above function we are decrementing
    // x so we will store all the possible sum values cases lesser than x in dp array 
    // int ans = solveMem(num, x, dp);
    // if(ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;

    return solveTab(num, x);

}
int main()
{
    
    
}
