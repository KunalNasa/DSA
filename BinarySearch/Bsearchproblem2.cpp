#include<iostream>
using namespace std;
int peakelement(int arr[], int n)
{
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    while (start < end)
    {
        if(arr[mid+1] > arr[mid])
        {
            start = mid+1;
        }
        else
        {
            end  = mid;
        }
        mid = start + (end-start)/2;
    }
    return end;
}
int main()
{
    int odd[7] = {0,1,2,3,4,1,0};
    int peak = peakelement(odd,7);
    cout<<"Peak element is "<<peak<<endl;
}