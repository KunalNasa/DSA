#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &mat, int &maxi)
{
    if(i >= mat.size() || j >= mat.size())
    {
        return 0;
    }   
    
    int right = solve(i, j + 1, mat, maxi);
    int dia = solve(i + 1, j + 1, mat, maxi);
    int bottom = solve(i + 1, j, mat, maxi);
    
    if(mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(dia, bottom));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int solveMem(int i, int j, vector<vector<int>> &mat, int &maxi,  vector<vector<int>> &dp)
{
    if(i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int right = solveMem(i, j + 1, mat, maxi, dp);
    int dia = solveMem(i + 1, j + 1, mat, maxi, dp);
    int bottom = solveMem(i + 1, j, mat, maxi, dp);
    
    if(mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(dia, bottom));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return 0;
    }
}
int solveTab(vector<vector<int>> &mat, int &maxi)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j+1];
            int dia = dp[i+1][j+1];
            int bottom = dp[i+1][j];
            
            if(mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(bottom, dia));
                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int solveSO(vector<vector<int>> &mat, int &maxi)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            int right = curr[j+1];
            int dia = next[j+1];
            int bottom = next[j];
            
            if(mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(bottom, dia));
                maxi = max(curr[j], maxi);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maxi;
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        // solve(0, 0, mat, maxi);
        vector<vector<int>> dp(n,vector<int> (m, -1));
        // solveMem(0,0,mat,maxi, dp);
        
        // solveTab(mat, maxi);
        solveSO(mat, maxi);
        return maxi;
    } 

int main()
{

}