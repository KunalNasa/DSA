#include<iostream>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> > ans)
{
    // base case
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude case
    solve(nums, output, index + 1, ans);

    // include case
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1 , ans);
}
vector<vector<int> > subsets(vector<int> &nums)
{
    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);

    return ans;
}
int main()
{
     vector<int> nums;
     nums.push_back(1);
     nums.push_back(2);
     nums.push_back(3);

    vector<vector<int> > result = subsets(nums);
    for (const vector<int>& subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}