#include <iostream>
using namespace std;
int pivotelement(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return e;
}
int searching(int arr[], int n, int key)
{
    int pivot = pivotelement(arr, n);
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        int start = pivot, end = n - 1;
        int mid = start + (start - end) / 2;
        while (start <= end)
        {
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (key > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (start - end) / 2;
        }
        return -1;
    }
    else
    {
        int start = 0, end = pivot - 1;
        int mid = start + (end-start) / 2;
        while (start <= end)
        {
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (key > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end-start) / 2;
        }
        return -1;
    }
}
int main()
{
    int arr[4] = {4,8,9,2};
    int index = pivotelement(arr, 4);
    cout << index << endl;
    int search = searching(arr, 4, 2);
    cout << "Index of key is: " << search << endl;
}