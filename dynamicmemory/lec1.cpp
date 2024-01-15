#include<iostream>
using namespace std;
int getsum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int& func(int a)
{
    int num = a;
    int& ans = num;
    return ans;
}
void update(int &n)
{
    // int &n ---> A reference variable
    // called by reference 
    // updated value will reflect in main function
    n = n + 1;
}
int main()
{
    int i = 5;
    int &j = i;
    cout<<i<<endl;
    cout<<j<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;

    int n = 9;
    cout<<"Before "<<n<<endl;
    update(n);
    cout<<"After "<<n<<endl; 

    int size;
    cin>>size;
    //variable size array
    int *arr = new int(size);
    //taking input from user
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans = getsum(arr,n);
    cout<<ans<<endl;   
}