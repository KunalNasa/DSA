#include<iostream>
#include<list>
using namespace std;
 int thirdLargest(int a[], int n)
    {
        if(n >= 3)
        {
            sort(a, a + n);
            return a[n-3];
        }
        else
        {
            return -1;
        }
        
    }
int main()
{
    list<int> l;
    list<int> n(5,100);
    l.push_back(2);
    l.push_front(1);
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of list "<<l.size()<<endl;

    for(int i:n)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    int arr[5] = {1,6,4,2,5};
    cout<< thirdLargest(arr,5)<<endl;
    int mini = __algo_gcd(3,4);
    cout<<mini<<endl;
    
}