#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        // moving to right part
        if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            // key<arr[mid] so searching in left part.
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int odd[5] = {1, 3, 5, 7, 9};
    int even[6] = {3, 4, 6, 7, 9, 12};
    int index = binarySearch(even, 6, 9);
    cout << "The index of 9 is " << index << endl;
}