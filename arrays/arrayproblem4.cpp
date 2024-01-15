#include <iostream>
using namespace std;
void pairsum(int arr[], int n, int key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                if (arr[i] + arr[j] == key)
                {
                    cout << arr[i] << " " << arr[j] << endl;
                    arr[i] = INT16_MIN, arr[j] = INT16_MIN;
                    break;
                }
            }
        }
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    pairsum(arr, 5, 6);
}