#include<iostream>
using namespace std;
class kQueue
{
    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];

        for(int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        arr = new int[n];
        next = new int[n];

        for(int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freeSpot = 0;
    }
    void enqueue(int x, int qn)
    {
        //overflow condition
        if(freeSpot == -1)
        {
            cout << "No free space available " << endl;
            return;
        }
        
        // find first index
        int index = freeSpot;

        //update freeSpot
        freeSpot = next[index];

        //check whether its first element
        if(front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        } 
        else
        {
            //link new element to the previous element
            next[rear[qn - 1]] = index;
        }

        //update next
        next[index] = -1;

        // update rear 
        rear[qn - 1] = index;

        // push element 
        arr[index] = x;
    }

    int dequeue(int qn)
    {
        if(front[qn - 1] == -1)
        {
            cout << "Queue is empty " << endl;
            return -1;
        }

        // find index to pop 
        int index = front[qn - 1];

        // front ko aage badhao
        front[qn - 1] = next[index];

        //manage freeslots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
int main()
{
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;


    

}