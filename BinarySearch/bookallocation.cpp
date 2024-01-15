// #include <iostream>
// using namespace std;
// bool ispossible(int arr[], int n, int m, int mid)
// {
//     int studentcount = 1;
//     int pagesum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (pagesum + arr[i] <= mid)
//         {
//             pagesum += arr[i];
//         }
//         else
//         {
//             studentcount++;
//             if (studentcount > m || arr[i] > mid)
//             {
//                 return false;
//             }
//             pagesum = arr[i];
//         }
//     }
//     return true;
// }
// int check(int arr[], int n, int m)
// {
//     int s = 0, e = 0, ans;
//     for (int i = 0; i < n; i++)
//     {
//         e += arr[i];
//     }
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (ispossible(arr, n, m, mid))
//         {
//             ans = mid;
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
//     int arr[4] = {10, 20, 30, 40};
//     cout << check(arr, 4, 2) << endl;
// }

#include <iostream>
using namespace std;
// bool ispossible(int arr[], int n, int m, int mid)
// {
//     int painterscore = 1;
//     int unit = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(unit + arr[i] <= mid)
//         {
//             unit += arr[i];
//         }
//         else
//         {
//             painterscore++;
//             if(painterscore > m || arr[i] > mid)
//             {
//                 return false;
//             } 
//             unit  = arr[i];

//         }
//     }
//      return true;
    
// }
// int check(int arr[], int n, int m)
// {
//     int s = 0, e = 0;
//     int ans;
//     for (int i = 0; i < n; i++)
//     {
//         e += arr[i];
//     } 
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (ispossible(arr, n, m, mid))
//         {
//             ans = mid;
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
//     int arr[4] = {5, 5, 5, 5};
//     cout<<check(arr,4,2)<<endl;
// }
int ispossible(int arr[], int n, int m, int mid)
{
    int studentcount = 1;
    int totalpages = 0;
    for (int i = 0; i < n; i++)
    {
        if(totalpages + arr[i] <= mid)
        {
            totalpages += arr[i];
        }
        else
        {
            studentcount++;
            if(studentcount > m || arr[i] > mid)
            {
                return false;
            }
            totalpages = arr[i];
        }
    }
    return true;

}
int bookallo(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    while (s<=e)
    {
        if(ispossible(arr,n,m,mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
    
}