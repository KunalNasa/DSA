#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,4> a = {1,2,3,4};
    cout<<"Size of array is "<<a.size()<<endl;
    cout<<"Empty or not- "<<a.empty()<<endl;
    cout<<"First element- "<<a.front()<<endl;
    cout<<"Last element- "<<a.back()<<endl;

}