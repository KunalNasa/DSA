#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //FIFO
    queue<string> q;
    q.push("Kunal");
    q.push("Nasa");
    q.push("Kannu");
    cout<<"First element "<<q.front()<<endl;
    cout<<"Size before "<<q.size()<<endl;
    q.pop();
    cout<<"First element "<<q.front()<<endl;
    cout<<"Size after "<<q.size()<<endl;


}