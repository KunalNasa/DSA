#include<iostream>
#include<queue>
using namespace std;

class Queue
{
    public:
    int *arr;
    int n;
    int qfront, rear;

    Queue(int size)
    {
        this->n = size;
        qfront = 0;
        rear = 0;
    }

    int pop()
    {
        if(qfront == rear)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    void push(int x)
    {
        if(rear == n)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = x;
            rear++;
        }
    }

    int front()
    {
        if(qfront == rear)
        {
            cout << "Queue is empty " << endl;
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    bool isEmpty()
    {
        if(qfront == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    /*
    // STL
    queue <int> q;
    q.push(10);
    q.push(5);
    q.push(13);

    cout << "size of queue is " << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << "size of queue is " << q.size() << endl;
    cout << q.front() << endl;

    cout << q.empty() << endl;
    */

    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.front() << endl;
    cout << q.pop() << endl;
    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl; 



    
}