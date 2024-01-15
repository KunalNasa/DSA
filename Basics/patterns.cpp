#include <iostream>
using namespace std;

int main()
{
    /*
    int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            char ch = 'A' + i - 1;
            cout<<ch;
            j++;
        }
        cout<<"\n";
        i++;
    }
    */
   /*
   int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        char ch = n -i +'A';
        while (j <= i)
        {
            cout<<ch;
            j++;
            ch++;
        }
        cout<<"\n";
        i++;
    }
    */
/*
    int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            if(n-j<i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        j++;
        }
        cout<<"\n";
        i++;
    }
    */
   /*
   int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 1;
    while (i<=n)
    {
        int j = 1;
        while (j<=n)
        {
            if(j<i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        j++;
        }
        cout<<"\n";
        i++;
    }
*/
/*
int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 0;
    while (i<=n)
    {
        int j = 0;
        while(j<2*n)
        {
            if(j<=n+i-1 && j>=n-i+1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        j++;
        }
        cout<<"\n";
        i++;
    }
*/
    int n;
    cout<<"Enter the number of rows\n";
    cin>>n;
    int i = 1;
    while (i<=n)
    {
        
            //printing spaces
            int space = n - i;
            while (space)
            {
                cout<<" ";
                space = space - 1;
            }
            // printing first triangle
            int j = 1;
            while (j<=i)
            {
                cout<<j;
                j++;
            }
            // printing second triangle
            int start = i-1;
            while (start)
            {
                cout<<start;
                start--; 
            }
            
        
        cout<<"\n";
        i++; 
}

}