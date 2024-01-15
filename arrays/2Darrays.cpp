#include<iostream>
using namespace std;
bool ispresent(int arr[][4], int rows,int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[i][j] == target)
            {
                return 1;
            }   
        }
    }
    return 0;
    
}
int main()
{
    int arr[3][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
    //row-wise input
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin>>arr[i][j];
    //     }
    // }
    //column-wise input
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin>>arr[j][i];
    //     }
    // } 
    // for (int i = 0; i < 3; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //         sum += arr[i][j]; //row sum
    //     }
    //     cout<<endl;
    //     cout<<sum<<endl;
    // }
    int maxi = INT16_MIN;
    int rowindex = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
            sum += arr[i][j]; //row sum
        }
        if(sum > maxi)
        {
            maxi = sum;
            rowindex = i;
        }
        cout<<endl;
    }
    cout<<rowindex<<endl;
    int target;
    cin>>target;
    if (ispresent(arr,3,target))
    {
        cout<<"Element is present in this array"<<endl;
    }
    else
    {
        cout<<"Element is not present in this array"<<endl;
    }
    
}