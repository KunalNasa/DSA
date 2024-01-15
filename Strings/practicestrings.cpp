// #include <iostream>
// using namespace std;
// int getlength(char name[])
// {
//     int count = 0;
//     for (int i = 0; name[i] != '\0'; i++)
//     {
//         count++;
//     }
//     return count;
// }
// char tolowercase(char ch)
// {
//     if('a'<ch && ch<'z')
//     {
//         return ch;
//     }
//     else
//     {
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }
// }
// bool palindrome(char name[], int n)
// {
//     int s = 0, e = n - 1;
//     while (s <= e)
//     {
//         if (tolowercase(name[s]) != tolowercase(name[e]))
//         {
//             return 0;
//         }
//         else
//         {
//             s++;
//             e--;
//         }
//     }
//     return 1;
// }
// int main()
// {
//     char name[10];
//     int n = getlength(name);
//     cout << "Enter your name: ";
//     cin >> name;
//     if (palindrome(name, n))
//     {
//         cout << "This name is a palindrome" << endl;
//     }
//     else
//     {
//         cout << "This name is not a plaindrome" << endl;
//     }
// }

// ----PROBLEM - 2-----
// #include<iostream>
// using namespace std;
// bool valid(char ch)
// {
//     if(('a'<ch && ch<'z') || ('A'<ch && ch<'Z')||('0'<ch && ch<'9'))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// char tolowercase(char ch)
// {
//     if('a'<ch && ch<'z')
//     {
//         return ch;
//     }
//     else
//     {
//         char temp = ch - 'A' + 'a';
//         return temp;
//     }
// }
// bool checkpalindrome(string a)
// {
//     int s = 0;
//     int e = a.length() - 1;
//     while(s<=e)
//     {
//         if(tolowercase(a[s]) != tolowercase(a[e]))
//         {
//             return 0;
//         }
//         else
//         {
//             s++;
//             e--;
//         }
//     }
//     return 1;
// }
// bool ispalindrome(string s)
// {
//     string temp = "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if(valid(s[i]))
//         {
//             temp.push_back(s[i]);
//         }
//     }
//     for (int i = 0; i < s.length(); i++)
//     {
//         temp[i] = tolowercase(temp[i]);
//     }
    
//     return checkpalindrome(temp);
// }
// using namespace std;
// int main()
// {
//     string a;
//     cout<<"Enter your string: "<<endl;
//     cin>>a;
//     cout<<ispalindrome(a)<<endl;
// }

//-----PROBLEM - 3------
#include<iostream>

using namespace std;
char maxocccharacter(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
    int maxi = -1, ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if(maxi<arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    return  ans + 'a';
}
using namespace std;
int main()
{
    string s;
    cout<<"Enter your string: ";
    cin>>s;
    cout<<maxocccharacter(s)<<endl;

}