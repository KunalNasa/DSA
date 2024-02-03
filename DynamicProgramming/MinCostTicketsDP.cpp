#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if(index >= n)
    {
        return 0;
    }

    // case 1
    int opt1 = cost[0] + solve(n, days, cost, index + 1);

    // case 7 & 30
    int i;
    for(i = index; i < n && days[i] < days[index] + 7; i++);
    int opt2 = cost[1] + solve(n, days, cost, i);

    for(i = index; i < n && days[i] < days[index] + 30; i++);
    int opt3 = cost[2] + solve(n, days, cost, i);

    return min(opt1, min(opt2, opt3));
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if(index >= n)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }
    // case 1
    int opt1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

    // case 7 & 30
    int i;
    for(i = index; i < n && days[i] < days[index] + 7; i++);
    int opt2 = cost[1] + solveMem(n, days, cost, i, dp);

    for(i = index; i < n && days[i] < days[index] + 30; i++);
    int opt3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(opt1, min(opt2, opt3));
    return dp[index];
}
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for(int k = n - 1; k >=0; k--)
    {
            // case 1
        int opt1 = cost[0] + dp[k + 1];

        // case 7 & 30
        int i;
        for(i = k; i < n && days[i] < days[k] + 7; i++);
        int opt2 = cost[1] + dp[i];

        for(i = k; i < n && days[i] < days[k] + 30; i++);
        int opt3 = cost[2] + dp[i];

        dp[k] = min(opt1, min(opt2, opt3));  
    }
    return dp[0];
}
int optimise(vector<int> &days, vector<int> &cost)
{
    queue<pair<int, int> > month;
    queue<pair<int, int> > week;
    int ans = 0;
    for(int day: days)
    {
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();

        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();

        month.push(make_pair(day, ans + cost[2]));
        week.push(make_pair(day, ans + cost[1]));

        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    // return solve(n, days, cost, 0);
    // return solveMem(n, days, cost ,0, dp);
    // return solveTab(n, days, cost);
    return optimise(days, cost);
}
int main()
{
    cout << " hello world: " << endl;
}
