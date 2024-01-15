// #include<iostream>
// using namespace std;
// void selection(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int temp = arr[i];
//         int j = i-1;
//         for (;j >= 0; j--)
//         {
//             if(arr[j] > temp)
//             {
//                 arr[j+1] = arr[j];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         arr[j+1] = temp;

//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// }
// int main()
// {
//     int arr[7] = {10,1,7,4,8,2,11};
//     selection(arr,7);
// }

#include <iostream>
using namespace std;
void insertion(int arr[], int n)
{
    int i = 1;
    while (i < n)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        // now j = -1;
        arr[j + 1] = temp;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {30, 9, 5, 2, 29};
    insertion(arr, 5);
}