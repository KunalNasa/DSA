#include<iostream>
#include <map>
#include <unordered_map>
using namespace std;
// unordered_map  -> order random
// ordered map -> order reserved

int main()
{
    // creation
    unordered_map<string, int> m;

    //insertion 
    //1
    pair<string, int> p = make_pair("joker", 3);
    m.insert(p);

    //2
    pair<string, int> pair2("naam", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;

    // what will happen
    m["mera"] = 2; //it is updation. The above one is insertion

    //search
    cout << m["mera"] << endl;
    cout << m.at("joker") << endl;
    // cout << m.at("unknownkey") << endl; // o/p = error

    cout << m["unknownkey"] << endl; // o/p = 0
    cout << m.at("unknownkey") << endl; // o/p = 0

    //size
    cout << m.size() << endl;

    //to check presence
    cout << m.count("bro") << endl;

    //erase
    m.erase("unknownkey");
    cout << m.size() << endl;

    // traverse
    // for(auto i:m)
    // {
    //     cout << i.first << " " << i.second << endl; 
    // }

    // traverse using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }

}