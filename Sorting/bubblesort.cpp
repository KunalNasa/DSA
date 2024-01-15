#include <iostream>
using namespace std;
void bubble(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    // for round 1 to n-1
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)  // decreasing length of array in every round
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {5, 10, 4, 50, 40};
    bubble(arr, 5);
}