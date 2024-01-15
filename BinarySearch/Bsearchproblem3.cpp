#include<iostream>
using namespace std;
int pivot(int arr[], int n)
{
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i]; 
    }
    int leftsum = 0;
    for (int i = 0; i < n; i++)
    {
        leftsum += arr[i];
        if (totalsum - leftsum == leftsum - arr[i])
        //totalsum - leftsum = right side sum
        //leftsum - arr[i] left side sum - middle index(required index).
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int even[5] = {1,4 ,3,2,1};
    int num = pivot(even,5);
    cout<<num<<endl;
}