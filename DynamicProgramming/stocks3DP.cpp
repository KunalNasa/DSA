#include <iostream>
using namespace std;
class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, int limit)
    {
        if(index >= prices.size())
        {
            return 0;
        }
        if(limit == 0)
            return 0;
        int profit = 0;
        if(buy)
        {
            profit = max((-1)*prices[index] + solve(index + 1, 0, prices, limit), 0 + solve(index + 1, 1, prices, limit));
        }
        else
        {
            profit = max(prices[index] + solve(index + 1, 1, prices, limit - 1), 0 + solve(index + 1, 0, prices, limit));
        }
        return profit;
    }
    int solveMem(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp)
    {
        if(index >= prices.size())
        {
            return 0;
        }
        if(limit == 0)
            return 0;
        
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;
        if(buy)
        {
            profit = max((-1)*prices[index] + solveMem(index + 1, 0, prices, limit, dp), 0 + solveMem(index + 1, 1, prices, limit, dp));
        }
        else
        {
            profit = max(prices[index] + solveMem(index + 1, 1, prices, limit - 1, dp), 0 + solveMem(index + 1, 0, prices, limit, dp));
        }
        return dp[index][buy][limit] =  profit;
    }
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        for(int index = n - 1; index >= 0; index--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if(buy)
                    {   
                        profit = max((-1)*prices[index] + dp[index + 1][0][limit], 0 + dp[index + 1][1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + dp[index + 1][1][limit - 1], 0 + dp[index + 1][0][limit]);
                    }
                    dp[index][buy][limit] =  profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solveSO(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));

        for(int index = n - 1; index >= 0; index--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if(buy)
                    {   
                        profit = max((-1)*prices[index] + next[0][limit], 0 + next[1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + next[1][limit - 1], 0 + next[0][limit]);
                    }
                    curr[buy][limit] =  profit;
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
    int solveSObest(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        // vector<vector<int>> curr(2, vector<int> (3, 0));
        // vector<vector<int>> next(2, vector<int> (3, 0));
        vector<int> curr1(3, 0);
        vector<int> curr0(3, 0);
        vector<int> next1(3, 0);
        vector<int> next0(3, 0);

        for(int index = n - 1; index >= 0; index--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if(buy)
                    {   
                        profit = max((-1)*prices[index] + next0[limit], 0 + next1[limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + next1[limit - 1], 0 + next0[limit]);
                    }
                    if(buy)
                        curr1[limit] =  profit;
                    else
                        curr0[limit] = profit;
                }
            }
            next1 = curr1;
            next0 = curr0;
        }
        return curr1[2];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(0,1, prices, 2);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        // return solveMem(0,1, prices, 2, dp);
        // return solveTab(prices);
        // return solveSO(prices);
        return solveSObest(prices);


        
    }
};
int main()
{
    
    
}