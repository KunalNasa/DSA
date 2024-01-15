#include<iostream>
using namespace std;
void copy(int arr[], int n)
{ 
    int key;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == key)
        {
            sum = sum + 1;
        }
    }
    if (sum == 1)
    {
        cout<<key<<" is the unique element"<<endl;
    }
    }
}

//XOR - 0^a = a
//    - a^a = 0
int alternatesol(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}
    
void duplicate(int arr[], int n)
{ 
    int key;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == key)
        {
            sum = sum + 1;
        }
    }
    if (sum == 2)
    {
        cout<<key<<" is the duplicate element"<<endl;
        break;  
    }
    }
}
int main()
{
    int arr[7] = {1,2,2,1,2,2,5};
    int dup[5] = {1,2,3,4,3};
    copy(arr,7);
    cout<<alternatesol(arr,7)<<endl;
    duplicate(dup,5);

    
}