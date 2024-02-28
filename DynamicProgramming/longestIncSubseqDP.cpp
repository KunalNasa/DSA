#include <iostream>
using namespace std;
int getlen(int n, int a[], int index, int prevIndex)
    {
        if(index == n)
        {
            return 0;
        }
        int include = 0;
        if(a[index] > a[prevIndex] || prevIndex == -1)
            include = 1 + getlen(n, a, index + 1, index);
        
        int exclude = getlen(n, a, index + 1, prevIndex);
        
        return max(include, exclude);
        
    }
    int getlenMem(int n, int a[], int index, int prevIndex, vector<vector<int> > &dp)
    {
        if(index == n)
        {
            return 0;
        }
        if(dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];
            
        int include = 0;
        if(a[index] > a[prevIndex] || prevIndex == -1)
            include = 1 + getlenMem(n, a, index + 1, index, dp);
        
        int exclude = getlenMem(n, a, index + 1, prevIndex, dp);
        
        dp[index][prevIndex + 1] = max(include, exclude);
        return dp[index][prevIndex + 1];
        
    }
    int getlenTab(int n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int curr = n - 1; curr >= 0; curr--)
        {
            for(int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if(a[curr] > a[prev] || prev == -1)
                {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                
                int exclude = dp[curr + 1][prev + 1];
                
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int getlenSO(int n, int a[])
    {
        vector<int> prevEle(n + 1, 0);
        vector<int> currEle(n + 1, 0);
        for(int curr = n - 1; curr >= 0; curr--)
        {
            for(int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if(a[curr] > a[prev] || prev == -1)
                {
                    include = 1 + currEle[curr + 1];
                }
                
                int exclude = currEle[prev + 1];
                
                prevEle[prev + 1] = max(include, exclude);
            }
            currEle = prevEle;
        }
        return currEle[0];
    }
    int getlenOptimal(int n, int a[])
    {
        if(n == 0)
        {
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {
            if(a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                // find index of just greater element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return getlen(n, a, 0, -1);
        // return getlenMem(n, a, 0, -1, dp);
        // return getlenTab(n, a);
        // return getlenSO(n, a);
        return getlenOptimal(n, a);
    
    }
int main()
{
    
    
}