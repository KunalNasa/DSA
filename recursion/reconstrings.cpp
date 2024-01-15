// -----Reverse String using recursion------
// #include<iostream>
// using namespace std;
// Unlike array, string ki copy pass hoti hai functions me.
// string reverse(string S, int s, int e)
// {
//     if(s >= e)
//     {
//         return S;
//     }
//     swap(S[s],S[e]);

//     return reverse(S,++s,--e);
// }
// int main()
// {
//     string samp = "abcd";
//     cout<<reverse(samp,0,3)<<endl;
// }

// -------Check Palindrome--------
// #include<iostream>
// using namespace std;
// int isPalindrome(string S, int s, int e)
// {
//     if(s >= e)
//     {
//         return 1;
//     }

//     if(S[s++] != S[e--])
//     {
//         return 0;
//     }
//     else
//     {
//         return isPalindrome(S,s,e);
//     }

// }
// int main()
// {
//     string sample = "abcdba";
//     cout<<isPalindrome(sample,0,4)<<endl;
// }

// A to the power B
#include <iostream>
using namespace std;
// int ApowerB(int a, int b, int ans = 1)
// {
//     // NOT AN OPTIMISED APPROACH
//     if (b == 0)
//     {
//         return ans;
//     }

//     ans = ans * a;
//     return ApowerB(a,--b, ans);
    
// }
// OPTIMISED SOLUTION
int findpower(int a, int b)
{
    // Base case
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }

    // recursive call
    int ans = findpower(a, b/2);

    // if b is even
    if(b % 2 == 0)
    {
        return ans * ans;
    }
    // if b is odd
    else
    {
        return a * ans * ans;
    }
}
int main()
{
    int a, b;
    cout << "Enter a number" << endl;
    cin >> a;
    cout << "Enter a power of a number" << endl;
    cin >> b;
    // cout << ApowerB(a,b) << endl;
    cout << findpower(a,b) << endl;
}