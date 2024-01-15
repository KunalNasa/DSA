#include<iostream>
using namespace std;
void sorting(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }
    
}
int main()
{
    int arr[8] = {0,1,1,0,1,2,3,0};
    sorting(arr,8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    
    }
    
}