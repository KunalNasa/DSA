// #include<iostream>
// using namespace std;
// void solve(vector<int> &nums,vector<vector<int> > &ans, int index, vector<int> output )
// {
//     if(index >= nums.size())
//     {
//         ans.push_back(output);
//         return;
//     }

//     // jab kuch add nahi karna
//     solve(nums,ans,index + 1, output);

//     //jab subset banana ho
//     int added = nums[index];
//     output.push_back(added);
//     solve(nums,ans,index + 1, output);
// }
// vector<vector<int> > subsets(vector<int> &nums)
// {
//     vector<vector<int> > ans;
//     int index = 0;
//     vector<int> output;
//     solve(nums,ans,index, output);
// }
// int main()
// {

// }

// #include <iostream>
// using namespace std;
// void solve(vector<string> &ans, int index, string output, string mapping[], string digits)
// {
//     if (index >= digits.size())
//     {
//         ans.push_back(output);
//         return;
//     }

//     int value = digits[index] - '0';
//     string traverse = mapping[value];
//     for (int i = 0; i < traverse.length(); i++)
//     {
//         output.push_back(traverse[i]);
//         solve(ans, index + 1, output, mapping, digits);
//         output.pop_back();
//     }

// }
// vector<string> lettercombinations(string digits)
// {
//     vector<string> ans;
//     int index = 0;
//     string output;
//     string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     solve(ans, index, output, mapping, digits);
// }

// int main()
// {

// }

// #include<iostream>
// using namespace std;
// void solve(vector<vector<int> > &ans, vector<int> nums,int index)
// {
//     if(index >= nums.size())
//     {
//         ans.push_back(nums);
//         return ;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         swap(nums[index],nums[i]);
//         solve(ans, nums, index + 1);
//         swap(nums[index],nums[i]);
//     }

// }
// vector<vector<int> > digitspermutation(vector<int> &nums)
// {
//     vector<vector<int> > ans;
//     int index = 0;
//     solve(ans, nums, index);
// }
// int main()
// {

// }
#include <iostream>
bool isvalid(int x, int y, vector<vector<int>> m, vector<vector<int>> temp, int n)
{
    if ((x > 0 && x < n) && (y > 0 && y < n) && (temp[x][y] == 0) && (m[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
using namespace std;
void solve(vector<vector<int>> m, vector<vector<int>> temp, vector<string> &ans,
           int xcor, int ycor, int n, string output)
{
    if (xcor == n - 1 && ycor == n - 1)
    {
        ans.push_back(output);
        return;
    }
    temp[xcor][ycor] = 1;

    // left
    int newx = xcor;
    int newy = ycor - 1;
    if (isvalid(newx, newy, m, temp, n))
    {
        output.push_back('L');
        solve(m, temp, ans, newx, newy, n, output);
        output.pop_back();
    }
    // right
    newx = xcor;
    newy = ycor + 1;
    if (isvalid(newx, newy, m, temp, n))
    {
        output.push_back('R');
        solve(m, temp, ans, newx, newy, n, output);
        output.pop_back();
    }

    // up
    newx = xcor - 1;
    newy = ycor;
    if (isvalid(newx, newy, m, temp, n))
    {
        output.push_back('U');
        solve(m, temp, ans, newx, newy, n, output);
        output.pop_back();
    }

    // down
    newx = xcor + 1;
    newy = ycor;
    if (isvalid(newx, newy, m, temp, n))
    {
        output.push_back('D');
        solve(m, temp, ans, newx, newy, n, output);
        output.pop_back();
    }

    temp[xcor][ycor] = 0;
}
vector<string> findpath(vector<vector<int>> &m, int n)
{
    int srcx = 0, srcy = 0;
    vector<vector<int>> temp = m;
    vector<string> ans;

    if (m[0][0] == 0)
    {
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
        }
    }
    string output = "";

    solve(m, temp, ans, srcx, srcy, n, output);

    sort(ans.begin(), ans.end());

    return ans;
}
int main()
{
}