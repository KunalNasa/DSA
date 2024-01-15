// #include<iostream>
// #include <algorithm>
// using namespace std;

// long long appleAndCoupon(int n, int m, vector<int> arr){
//     sort(arr.begin(), arr.end());
//     long long free = arr[n - m];
//     long long coins = 0;
//     for(int i = 0; i < n; i++)
//     {
//         coins += arr[i];
//     }
//     coins = coins - free;
//     return coins;
// }
// int main()
// {
//     vector <int> arr;
//     arr.push_back(5);
//     arr.push_back(2);
//     arr.push_back(4);
//     arr.push_back(1);
//     arr.push_back(3);

//     cout<<appleAndCoupon(5, 3, arr);
// }

#include<iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int * first = new int[len1];
    int * second = new int[len1];
    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;

    for (int i = 0; i < len1; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = s;

    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++]; 
    }
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left part
    mergeSort(arr, s, mid);

    // right part 
    mergeSort(arr, mid + 1, e);

    // merging both parts
    merge(arr, s, e);
}
int main()
{
    
}