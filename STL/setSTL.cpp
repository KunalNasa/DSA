//insert, find, erase, count - all with T.C - O(log N)
//size, begin, empty - all with T.C - O(N)
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(40);
    s.insert(5);
    for (int i : s)
    {
        // ordered set(slow).
        cout << i << endl;
    }
    cout<<endl;

    // s.erase(s.begin());
    // for (int i : s)
    // {
    //     // ordered set(slow).
    //     cout << i << endl;
    // }
    cout<<"count "<<s.count(2)<<endl;
}