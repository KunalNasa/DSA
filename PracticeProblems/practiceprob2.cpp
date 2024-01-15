// #include <iostream>
// using namespace std;
// int firstocc(int arr[], int n, int key)
// {
//     int s = 0, e = n - 1;
//     int mid = s + (e - s) / 2;
//     int ans;
//     while (s <= e)
//     {
//         if (arr[mid] == key)
//         {
//             ans = mid;
//             e = mid - 1;
//         }
//         else if (arr[mid] > key)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return ans;
// }
// int lastocc(int arr[], int n, int key)
// {
//     int s = 0, e = n - 1;
//     int mid = s + (e - s) / 2;
//     int ans;
//     while (s <= e)
//     {
//         if (arr[mid] == key)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else if (arr[mid] > key)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return ans;
// }
// int main()
// {
//     int arr[5] = {0, 2, 2, 2, 2};
//     int index1 = firstocc(arr, 5, 2);
//     int index2 = lastocc(arr, 5, 2);
//     cout << "Index of first occurence is " << index1 << endl;
//     cout << "Index of last occurence is " << index2 << endl;

// }

//--------------------PROBLEM 2 ----------------------
#include<iostream>
using namespace std;
int peakelement(int arr[], int n)
{
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    while(s < e)
    {
        if(arr[mid] > arr[mid+1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return e;

}
int main()
{
    int arr[7] = {-1,0,1,2,1,0,-1};
    int index = peakelement(arr,7);
    cout<<"The index of peak element is "<<index<<endl;

}