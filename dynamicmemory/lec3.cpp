// #include<iostream>
// using namespace std;
// int secondlargest(int arr[], int n)
// {
//     int first, second;
//     first = INT16_MIN;
//     second = INT16_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] > first)
//         {
//             second = first;
//             first = arr[i];
//         }
//         else if (arr[i] > second && arr[i] != first) 
//         {
//             second = arr[i];
//         }
//     }
//     return second;
// }
// bool fascinating(int n)
// {
//         int m2 = 2*n;
// 	    int m3 = 3*n;
// 	    int arr[9];
// 	    int sum = 0;
//         string mainstr = "123456789";
// 	    string str = to_string(n) + to_string(m2) + to_string(m3);
//         cout<<str<<endl;
//         sort(str.begin(), str.end());
//         if(mainstr == str)
//         {
//             return 1;
//         }
//         return 0;
// }
// int main()
// {
//     int arr[6] = {100, 35, 1, 10, 34, 1};
//     // cout<<secondlargest(arr,6)<<endl;
//     cout<<fascinating(264);
// }

//------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
// If we put a space between the macro name and the parentheses in the macro definition,
// then the macro will not work.
#define PI 3.14
#define AREA(l,b) (l*b)
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 130
//Function like macro definition
#define min(a,b) (((a) < (b)) ? (a) : (b))

int a = 15; //Global variable
int main()
{
    int r = 5, l = 10, b = 5;
    double area = PI * r * r;
    cout<<"Area is "<<area<<endl;
    cout<<"Area is "<<AREA(l,b)<<endl;
    cout<<"I have "<<FOLLOWERS<<" followers on instagram"<<endl;
    cout<<"Minimum of 5, 10 is "<<min(l,b)<<endl;
    cout<<a<<endl;



}