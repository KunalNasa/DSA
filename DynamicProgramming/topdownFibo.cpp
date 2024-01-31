#include <iostream>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    if(n <= 1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for(int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fibo(n, dp) << endl;

    int k;
    cin >> k;
    // step 1
    vector<int> dp2(k + 1);

    // step 2
    dp2[1] = 1;
    dp2[0] = 0;

    // step 3
    for(int i = 2; i <= k; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }
    cout << dp2[k] << endl;

    int j;
    cin >> j;
    if(j == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int prev1 = 1;
    int prev2 = 0;
    for(int i = 2; i <= j; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
    return 0;
}
