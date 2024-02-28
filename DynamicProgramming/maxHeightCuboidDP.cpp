#include<iostream>
using namespace std;

class Solution {
    bool check(vector<int> base, vector<int> newCub)
    {
        if(newCub[0] <= base[0] && newCub[1] <= base[1] && newCub[2] <= base[2])
        {
            return true;
        }
        return false;
    }
    int solve(int n, vector<vector<int>> &cuboids)
    {

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for(int curr = n - 1; curr >= 0; curr--)
        {
            for(int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    include = cuboids[curr][2] + nextRow[curr + 1];
                }

                int exclude = nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow; 
        }
        return nextRow[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &a: cuboids)
        {
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());
        
        return solve(cuboids.size(), cuboids);

    }
};

int main()
{
    
}