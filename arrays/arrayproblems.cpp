#include<iostream>
using namespace std;
void revalternate(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i = i+2)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
}
int main()
{
    int array[6] = {1,2,3,4,5,6};
    revalternate(array,6);

}