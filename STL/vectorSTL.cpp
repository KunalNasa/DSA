#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v; //Dynamic array
    //If size is already known
    vector<int> a(5,1); //5 size ka array with all element = 1;

    vector<int> last(a); //isme a vector copy hogaya. "a" ke saare elements isme aagye
    // for(int i:last)
    // {
    //     cout<<i<<" ";
    // }
    cout<<endl;
    cout<<"Capacity - "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capacity - "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity - "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity - "<<v.capacity()<<endl;
    v.push_back(5);
    v.push_back(4);
    cout<<"Capacity - "<<v.capacity()<<endl;
    cout<<"Size- "<<v.size()<<endl;


    cout<<"Element at index 2 is  "<<v.at(2)<<endl;

    cout<<"First "<<v.front()<<endl;
    cout<<endl;
    cout<<"Last "<<v.back()<<endl;
    cout<<endl;
 
    cout<<"Before pop "<<endl;
    for (int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    v.pop_back();
    cout<<"After pop "<<endl;
    for (int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    // cout<<"Size before clear "<<v.size()<<endl;
    // v.clear();
    // cout<<"Size after clear "<<v.size() <<endl; 

}