#include<iostream>
using namespace std;
void compare(int arr1[],int n1, int arr2[],int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout<<arr1[i]<<" ";
                break;
            }
            
        }
        
    }
}
//Two Pointer approach method.
//Applicable when array is sorted in ascendig or descending order.
//Here we are applying for ascending order.
void twopointerapproach(int arr1[],int n1, int arr2[],int n2)
{
    int i = 0, j = 0;
   while(i<n1 && j<n2)
   {
        if (arr1[i]<arr2[j])
        {
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else
        {
            //when arr1[i]>arr2[j]
            j++;
        }
        
   }
}
int main()
{
    int arr1[5] = {1,2,3,5,3}, arr2[3] = {1,2,3};
    // compare(arr1,5,arr2,3);
    twopointerapproach(arr1,5,arr2,3);
    
}