#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
int solve(int i, int j, vector<int>& v) {
        if (i + 1 == j)
        {
            return 0;
        }
        
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) 
        {
            ans = min(ans, v[i]*v[j]*v[k] + solve(i, k, v) + solve(k, j, v));
        }
        return ans;
    }

	int solveMem(int i, int j, vector<int>& v, vector<vector<int>> &dp) {
        if (i + 1 == j)
        {
            return 0;
        }
		if(dp[i][j] != -1)
		{
			return dp[i][j];
		}
        
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) 
        {
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(i, k, v, dp) + solveMem(k, j, v, dp));
        }
		dp[i][j] = ans;
        return dp[i][j];
    }
	int solveTab(vector<int>& v, int n) {
		vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 1; i >= 0; i--)
		{
			for(int j = i + 2; j < n; j++)
			{
				int ans = INT_MAX;
        		for (int k = i + 1; k < j; k++) 
        		{
            		ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
        		}
				dp[i][j] = ans;
			}
		}
        return dp[0][n-1];
    }
int minimumTriangleScore(vector<int> &arr, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (n, -1));
	// return solve(0, n - 1, arr);
	// return solveMem(0, n - 1, arr, dp);
	return solveTab(arr, n);
}
int main()
{
    
}