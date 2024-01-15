// The lower_bound() method in C++ is used to return an iterator pointing to the first   element in the range [first, last) which has a value not less than val. This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, lower_bound() returns the iterator of the first such value.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(12);
    v.push_back(20);
    v.push_back(7);
    v.push_back(9);
    // cout<<binary_search(v.begin(),v.end(),5)<<endl;//searching for 5
    cout<<"Finding 12 "<<binary_search(v.begin(),v.end(),12)<<endl;//searching for 12
    cout<<"Lower bound "<<lower_bound(v.begin(),v.end(),20)-v.begin()<<endl;
    cout<<"upper bound "<<upper_bound(v.begin(),v.end(),1)-v.begin()<<endl;
    int a = 3, b =5;
    cout<<"minimum "<<min(a,b)<<endl;
    cout<<"maximum "<<max(a,b)<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<abcd<<endl;
    rotate(v.begin(),v.begin() + 1, v.end());
    for(int i:v)
    {
        cout<<i<<endl;
    }
     
}