#include<iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i])
            {
                // temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
                swap(arr[i],arr[j]);
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
    int arr[5] = {50,34,60,12,58};
    selectionsort(arr,5);
}