#include <iostream>
using namespace std;
int solve(vector<int> &nums1, vector<int> &nums2, int index, int swapped)
{
    if (index >= nums1.size())
        return 0;

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if (swapped)
        swap(prev1, prev2);

    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index + 1, 0);

    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

    return ans;
}
int solveMem(vector<int> &nums1, vector<int> &nums2, int index, int swapped, vector<vector<int>> &dp)
{
    if (index >= nums1.size())
        return 0;

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if (swapped)
        swap(prev1, prev2);

    if (dp[index][swapped] != -1)
        return dp[index][swapped];
    if (nums1[index] > prev1 && nums2[index] > prev2)
        ans = solveMem(nums1, nums2, index + 1, 0, dp);

    if (nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));

    dp[index][swapped] = ans;
    return dp[index][swapped];
}
int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));
    int n = nums1.size();
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
                swap(prev1, prev2);

            if (nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = dp[index + 1][0];
            }

            if (nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1 + dp[index + 1][1]);
            }
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}
int solveSO(vector<int> &nums1, vector<int> &nums2)
{
    int swap = 0, currswap = 0;
    int noswap = 0, currnoswap = 0;
    int n = nums1.size();
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if (swapped)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }

            if (nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = noswap;
            }

            if (nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1 + swap);
            }
            // dp[index][swapped] = ans; replaced by
            if (swapped)
                currswap = ans;
            else
                currnoswap = ans;
        }
        swap = currswap;
        noswap = currnoswap;
    }
    // return dp[1][0];
    return min(swap, noswap);
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // it means that the previous index is swapped or not
    int swapped = 0;
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));

    // return solve(nums1, nums2, 1, swapped);
    // return solveMem(nums1, nums2, 1, swapped, dp);
    // return solveTab(nums1, nums2);
    return solveSO(nums1, nums2);
}
int main()
{
}