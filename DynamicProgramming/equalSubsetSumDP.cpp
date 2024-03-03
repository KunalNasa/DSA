#include <iostream>
using namespace std;
bool solve(int arr[], int N, int target, int index)
{
    if (index >= N)
        return 0;

    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    int include = solve(arr, N, target - arr[index], index + 1);
    int exclude = solve(arr, N, target, index + 1);

    return include or exclude;
}
bool solveMem(int arr[], int N, int target, int index, vector<vector<int>> &dp)
{
    if (index >= N)
        return 0;

    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    int include = solveMem(arr, N, target - arr[index], index + 1, dp);
    int exclude = solveMem(arr, N, target, index + 1, dp);

    dp[index][target] = include or exclude;
    return dp[index][target];
}

bool solveTab(int N, int arr[], int target)
{
    vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }
    for (int index = N - 1; index >= 0; index--)
    {
        for (int j = 0; j <= target; j++)
        {
            int include = 0;
            if (j - arr[index] >= 0)
                include = dp[index + 1][j - arr[index]];
            int exclude = dp[index + 1][j];

            if (include == 1 || exclude == 1)
            {
                dp[index][j] = 1;
            }
        }
    }
    return dp[0][target];
}
bool solveSO(int N, int arr[], int target)
{

    vector<int> curr(target + 1);
    vector<int> next(target + 1);
    curr[0] = 1;
    next[0] = 1;

    for (int index = N - 1; index >= 0; index--)
    {
        for (int j = 0; j <= target; j++)
        {
            int include = 0;
            if (j - arr[index] >= 0)
                include = next[j - arr[index]];
            int exclude = next[j];

            if (include == 1 || exclude == 1)
            {
                curr[j] = 1;
            }
        }
        next = curr;
    }
    return next[target];
}
int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }
    if (total % 2 != 0)
    {
        return 0;
    }
    int target = total / 2;
    vector<vector<int>> dp(N, vector<int>(target + 1, -1));
    // return solve(arr, N, target, 0);
    // return solveMem(arr, N, target, 0, dp);
    // return solveTab(N, arr, target);
    return solveSO(N, arr, target);
}
int main()
{
}
