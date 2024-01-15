// #include<iostream>
// using namespace std;
// void bubble(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         bool swapped = false;
//         for (int j = 0; j < n-i; j++)
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 swap(arr[j],arr[j+1]);
//                 swapped = true;
//             }
            
//         }
//         if (swapped == false)
//             {
//                 break;
//             }
        
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }
// int main()
// {
//     int arr[5] = {1,400,23,40,10};
//     bubble(arr, 5);
// }

//-------MAX-MIN ELEMENT OF AN ARRAY-------
// #include<iostream>
// using namespace std;
// int maxelement(int arr[], int n)
// {
//     int maxi = INT16_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] > maxi)
//         {
//             maxi = arr[i];
//         }
//     }
//     return maxi;
// }
// int minelement(int arr[], int n)
// {
//     int maxi = INT16_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] < maxi)
//         {
//             maxi = arr[i];
//         }
//     }
//     return maxi;
// }
// int reverse(int arr[], int n)
// {
//     int temp;
//     for (int i = 0; i < n/2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[n-i-1];
//         arr[n-i-1] = temp;
//     }
//     return 0;
// }
// int main()
// {
//     int arr[5] = {1,2,3,4,500};
//     reverse(arr,5);
//     for (int i = 0; i < 5; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     int maxi = maxelement(arr,5);
//     cout<<maxi<<endl;
//     int mini = minelement(arr,5);
//     cout<<mini<<endl;
// }

// #include<iostream>
// using namespace std;
// int indexmax(int arr[], int n, int k)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < n-1; j++)
//         {
//             if(arr[j+1] > arr[j])
//             {
//                 swap(arr[j],arr[j+1]);
//             }
//         }
        
//     }
//     return arr[k-1];
// }
// int main()
// {
//     int arr[7] = {3,5,9,10,40,35,4};
//     int element = indexmax(arr,7,2);
//     for (int i = 0; i < 7; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<element<<endl;
// }

#include<iostream>
using namespace std;
void selection(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j],arr[i]);
            }
        }    
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[5] = {0,2,1,2,0};
    selection(arr,5);
}