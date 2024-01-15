#include<iostream>
using namespace std;

// void rotatearray(int arr[], int n)
// {
//     int temp[n];
//     for (int i = 0; i < n; i++)
//     {
//         temp[(i+1) % n] = arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }
// int palinArray(int arr[], int n)
// {
//     int index;
//     for (int i = 0; i < n; i++)
//     {
//         index = arr[i];
//         int iter = 0, ispalindrome = 0;
//         while (index > 0)
//         {
//             ispalindrome = ispalindrome*10 + index%10; 
//             index = index/10;
//             iter++; 
//         }
//         if (ispalindrome != arr[i])
//         {
//             return 0;
//         }
//     }
//     return 1;
    
// }
int main()
{
    /*
    int a,b=1;
    a = 10;
    if(++a) //it will be a non zero value and every non zero value in cpp is true.So,this
    // if statement is true.
    {
        cout<<b;

    }
    else
    {
        cout<<++b;
    }
    */

    // for (int i = 0, j = 0; i < 5 && j<6; i++,j++)
    // {
    //     cout<<i<<"  "<<j<<endl;
    // }
/*
    int n, sum = 0;
    cout<<"Enter the number\n";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        sum = sum + i;
    }
    cout<<sum<<endl;
*/
// FIBONACCI SERIES
/*
int n;
cout<<"Enter an integer\n";
cin>>n;
int a = 0;
int b = 1;
cout<<a<<" "<<b<<" ";

for (int i = 1; i < n; i++)
{
    int nextnum = a + b;
    cout<<nextnum<<" ";
    a = b;
    b = nextnum;
}
*/
// int k;
// cout<<"Enter the number\n";
// cin>>k;
// for (int i = 2; i < k; i++)
// {
//     if(k%i == 0)
//     {
//        cout<<"Number is not a prime\n";
//        break;
//     }
//     else{
//         cout<<"Number is a prime\n";
//         break;
//     }
// }
}