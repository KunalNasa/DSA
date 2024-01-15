#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int, vector<int> , greater<int> > mini;
 
    maxi.push(1);
    maxi.push(10);
    maxi.push(3);
    maxi.push(0);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout<<maxi.top()<<" "; //sabse phle maximum element print hoga
        maxi.pop(); //size change hota jaa rha hai
    }
    cout<<endl;
    
    mini.push(1);
    mini.push(10);
    mini.push(3);
    mini.push(0);
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout<<mini.top() <<" "; //sabse phle minimum element
        mini.pop();
    }
    cout<<endl;

    cout<<"true or false "<<mini.empty()<<endl;

    
}