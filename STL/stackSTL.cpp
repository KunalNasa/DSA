#include<iostream>
#include<stack>
using namespace std;
int main()
{
    // LIFO
    stack<string> s;
    s.push("Kunal");
    s.push("Nasa");
    s.push("Kannu");
    cout<<"Top element is - "<<s.top()<<endl;
    s.pop();
    cout<<"Top element is - "<<s.top()<<endl;
    cout<<"Size of stack "<<s.size()<<endl;
    cout<<"Empty or not "<<s.empty()<<endl; 


}