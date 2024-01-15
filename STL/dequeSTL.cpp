//In deque we can perform push(insertion) operations at the beginning as well as at the end.
//unlike array, not contiguous memory location.
//It is dynamic
#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    // d.pop_back();
    // d.pop_front();

    // for(int i:d)
    // {
    //    cout<<i<<" ";
    // }
    cout<<"Element at index 1 "<<d.at(1)<<endl;
    cout<<"Empty or not "<<d.empty()<<endl;
    cout<<"Size before erase "<<d.size()<<endl;
    d.erase(d.begin(),d.begin() + 1);//to erase one element.
    cout<<"Size after erase "<<d.size()<<endl;
    
}