#include<iostream>
using namespace std;
#include<deque>
class Dequeue
{
    int *arr;
    int size;
    int front, rear;
    public:
    Dequeue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    
    bool pushFront(int x)
    {
        if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if(front == -1)
        {
            front = rear = 0;
        }
        else if(front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = x;
        return true;
    }

    bool pushBack(int x)
    {
        if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if(front == -1)
        {
            front = rear = 0;
        }
        else if(rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = x;
        return true; 
    }

    int popFront()
    {
        if(front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans  = arr[front];
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if(front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans  = arr[rear];
        arr[rear] = -1;  
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

};
int main()
{
    /*
    deque <int> dq;
    dq.push_front(12);
    dq.push_back(10);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    dq.pop_front();
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    */
}