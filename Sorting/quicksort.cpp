#include<iostream>
using namespace std;
// int partition(int *arr, int s, int e)
// {
//     int pivot = arr[s];
//     int count = 0;
//     for (int i = s + 1; i < e + 1; i++)
//     {
//         if(arr[i] <= pivot)
//         {
//             count++;
//         }
//     }

//     //place pivot at right index
//     int pivotIndex = s + count;
//     swap(arr[pivotIndex], arr[s]);

//     // left or right vaala part 
//     int p1 = s, p2 = e;

//     while(p1 < pivotIndex && p2 > pivotIndex)
//     {
//         while(arr[p1] < pivot)
//         {
//             p1++;
//         }

//         while(arr[p2] > pivot)
//         {
//             p2--;
//         }

//         if(p1 < pivotIndex && p2 > pivotIndex)
//         {
//             swap(arr[p1],arr[p2]);
//         }
//     }

  
//     return pivotIndex;
    
// }

// ------- OPTIMISED PARTITION CODE-------
int partition(int *arr, int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }    
    }
    swap(arr[e], arr[i+1]);

    return i + 1;    
}
void quickSort(int *arr, int s, int e)
{
    // Base case
    if(s >= e)
    {
        return;
    }

    //partition karenge
    int p = partition(arr, s, e);

    // left part sort karenge
    quickSort(arr, s, p - 1);

    // right part sort karenge
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[10] = {3,4,2,1,5,4,6,7,8,8};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for ( int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}