#include <iostream>
#include <math.h>
using namespace std;
void revarray(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
}
int main()
{
    // -------PROBLEM-1-------
    // int n, product = 1, sum = 0;
    // cout<<"Enter the number\n";
    // cin>>n;
    // while(n>0)
    // {
    //     int num = n%10;
    //     product = product*num;
    //     sum = sum+num;
    //     n = n/10;
    // }
    // cout<<product-sum<<endl;

    // ------PROBLEM-2------
    /*
    int n,sum = 0;
    cout<<"Enter your number";
    cin>>n;
    while (n>0)
    {
        if(n%10 == 1)
        {
            sum += 1;
        }
        n = n/10;
    }
    cout<<sum<<endl;
    */
    //-----PROBLEM-3-----
    /*
    int number;
    cout<<"Enter an integer: ";
    cin>>number;
    int revnumber = 0;
    while (number != 0)
    {
        // revnumber = revnumber * 10;
        revnumber = revnumber * 10 + (number%10);
        number =  number/10;
    }
    cout<<revnumber<<endl;
    */
    //-----PROBLEM-4-----
    /*
    int number;
    cout<<"Enter an integer: ";
    cin>>number;
    int i = 1, bin = 0 , rem;
    while(number != 0)
    {
     rem = number % 2;
     bin += rem * i;
     i = 10*i;
     number = number/2;
    }
    NOT SOLVED
    */
    //-----PROBLEM-5-----
    /*
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (number == 0)
    {
        return false;
    }
    else
    {
        while (number % 2 == 0)
        {
            number = number / 2;
        }
        if (number == 1)
        {
            cout << true << endl;
        }
        else
        {
            cout << false << endl;
        }
    }
    */
   int arrary1[6] = {1,2,3,4,5,6};
   revarray(arrary1,6);

    
}