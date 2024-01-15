#include<iostream>
#include<math.h>
using namespace std;
int missing(int array[], int n)
{
     int ans = 0, arraysum = 0;
       for(int i = 0; i < n; i++)
       {
           ans += i+1;
           arraysum += array[i];
       }
       return ans - arraysum;
}
int main()
{
    int arr[7] = {5,3,2,4,1,6};
    
    // int a = 200;
    // cout<< a << endl;
    /*
    int a = 'a';
    cout<<a << endl;
    char ch = 98;
    cout<<ch<<endl;
    char ch1 = 123456;
    cout <<ch1<<endl;
    */
   unsigned int a = -112;
   
}
