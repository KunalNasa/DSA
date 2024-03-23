#include <iostream>
using namespace std;
// can also be done using the concept of limits by changing the value of limit
// to k instead of 2
class Solution {
public:
    int solve(int index, vector<int> &prices, int k, int operationNo)
{
    if(index == prices.size())
        return 0;
    if(operationNo == 2*k)
        return 0;
    
    int profit = 0;
    if(operationNo % 2 == 0) // buy case
    {
        profit = max((-1)*prices[index] + solve(index + 1, prices, k, operationNo + 1), 0 + solve(index + 1, prices, k, operationNo));
    }
    else
    {
        profit = max(prices[index] + solve(index + 1, prices, k, operationNo + 1), 0 + solve(index + 1, prices, k, operationNo));
    }
    return profit;
}
int solveMem(int index, vector<int> &prices, int k, int operationNo, vector<vector<int>> &dp)
{
    if(index == prices.size())
        return 0;
    if(operationNo == 2*k)
        return 0;
    if(dp[index][operationNo] != -1)
        return dp[index][operationNo];
    
    int profit = 0;
    if(operationNo % 2 == 0) // buy case
    {
        profit = max((-1)*prices[index] + solveMem(index + 1, prices, k, operationNo + 1, dp), 0 + solveMem(index + 1, prices, k, operationNo, dp));
    }
    else
    {
        profit = max(prices[index] + solveMem(index + 1, prices, k, operationNo + 1, dp), 0 + solveMem(index + 1, prices, k, operationNo, dp));
    }
    return dp[index][operationNo] = profit;
}
int solveTab(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int> (2*k + 1, 0));
    for(int index = n - 1; index >= 0; index--)
    {
        for(int operationNo = 0; operationNo < 2*k; operationNo++)
        {
            int profit = 0;
    if(operationNo % 2 == 0) // buy case
    {
        profit = max((-1)*prices[index] + dp[index+1][operationNo + 1], 0 + dp[index+1][operationNo]);
    }
    else
    {
        profit = max(prices[index] + dp[index+1][operationNo + 1], 0 +dp[index+1][operationNo]);
    }
    dp[index][operationNo] = profit;

        }
    }
    return dp[0][0];

}
int solveSO(int k, vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>> dp(n + 1, vector<int> (2*k + 1, 0));
    vector<int> curr(2*k + 1, 0);
    vector<int> next(2*k + 1, 0);

    for(int index = n - 1; index >= 0; index--)
    {
        for(int operationNo = 0; operationNo < 2*k; operationNo++)
        {
            int profit = 0;
    if(operationNo % 2 == 0) // buy case
    {
        profit = max((-1)*prices[index] + next[operationNo + 1], 0 + next[operationNo]);
    }
    else
    {
        profit = max(prices[index] + next[operationNo + 1], 0 + next[operationNo]);
    }
    curr[operationNo] = profit;

        }
        next = curr;
    }
    return curr[0];

}
    int maxProfit(int k, vector<int>& prices) {
        // return solve(0, prices, k, 0);
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k + 1, -1));
        // return solveMem(0, prices, k, 0, dp);
        // return solveTab(k, prices);
        return solveSO(k, prices);
    }
};
int main()
{
    
    
}