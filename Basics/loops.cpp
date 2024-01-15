#include<iostream>
using namespace std;
int main(){
/*
int k;
cout<<"Enter your number\n";
cin>>k;
int i=1 , j=0;

while(i<=k)
{
cout<<i<<endl;
j= j + i;
i++;
}
cout<<j<<endl;
*/
/*
int n, sum = 0;
cout<<"Enter your number: \n";
cin>>n;
int i = 0;
while (i<=n)
{
    if (i%2 == 0)
    {
        sum = sum + i;
    }
    i++;
}
cout<<sum<<endl;
*/
/*
int n;
cout<<"Enter the number of rows\n";
cin>>n;
int count = 1;
int i = 1;
while(i<=n)
{
    int j = 1;
    while(j<=n)
    {
        cout<<count<<" ";
        count++;
        j++;
    }
    i++;
    cout<<"\n";
}
*/
/*
int n;
cout<<"Enter the number of rows\n";
cin>>n;
int i = 1;
while(i<=n)
{
    int j = 1;
    while(j<=i)
    {
        int count = 1;
        cout<<i-j +1;
        j++;
        count--;
    }
    i++;
    cout<<"\n";
}
*/

int n;
cout<<"Enter the number of rows\n";
// cin>>n;
n = 5;
int i = 1;

while(i<=n)
{
    int j = 1;
    while(j<=n)
    {
        char ch = 'A'+i+j-2;
        cout<<ch;
        j++;

    }
    i++;
    cout<<"\n";
}
}