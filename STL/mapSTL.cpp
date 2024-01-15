//Similar to the (relations and) functions of class 12, ek element ek hi chiz ko point
//kar sakta hai but do different elements bhi same cheez ko point kar sakte hai.
//a points to 1 and b can also points to 1. But a can not point to 1 and 2 both.
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int, string> m;
    m[1] = "Kunal";
    m[2] = "Nasa";
    m[3] = "Kannu";
    m.insert(make_pair(5,"bheem"));
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl; 
    }
    cout<<"Finding number "<<m.count(5)<<endl;
    m.erase(5);
    cout<<"Finding number after erase "<<m.count(5)<<endl;

    auto it = m.find(2);
    for(auto i = it; i !=m.end(); i++)
    {
        cout<<(*i).first<<endl;
    }
}