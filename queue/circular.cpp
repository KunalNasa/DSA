#include<iostream>
using namespace std;
class CircularQueue
{
    public:
    int qfront, rear;
    int *arr;
    int size;
    CircularQueue(int n)
    {
        this->size = n;
        qfront = -1;
        rear = - 1;

    }

    void push(int x)
    {
        if((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is full " << endl;
            return;
        }
        else if(qfront == -1)
        {
            qfront = rear = 0;
        }
        else if(rear == size - 1 && qfront != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    int pop()
    {
        if(qfront == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans  = arr[qfront];
        arr[qfront] = -1;
        if(qfront == rear)
        {
            qfront = rear = -1;
        }
        else if(qfront == size - 1)
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }
};
int main()
{
    
}