#include<iostream>
#include<queue>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;
    
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[size] = val;
        
        while(index > 1)
        {
            int parent = index / 2;
            //for max heap
            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromHeap()
    {
        if(size == 0)
        {
            cout << "Nothing to delete" << endl;
        }

        arr[1] = arr[size];
        int index = 1;
        size--;
        while(index < size)
        {
            int left = 2*index;
            int right = 2*index + 1;

            if(left < size && arr[index] < arr[left])
            {
                swap(arr[index], arr[left]);
                index = left;
            }
            else if(right < size && arr[index] < arr[right])
            {
                swap(arr[index], arr[right]);
                index = right;
            }
            else
            {
                return;
            }
        }

    }
    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

 
        if(left <= size && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(right <= size && arr[largest] < arr[right])
        {
            largest = right;
        }

        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, size, largest);
        }
}

void heapSort(int arr[], int size)
{
    int t = size;
    while(t > 1)
    {
        // step 1
        swap(arr[1], arr[t]);
        // step 2
        t--;
        // step 3
        heapify(arr, t, 1);

    }
}
int main()
{
    
    heap h;
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(30);
    h.print();
    h.deletefromHeap();
    h.print();

    int arr[7] = {-1, 50, 20, 52, 58, 60, 64};
    int n = 6;

    for(int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, 6);

    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // max heap formation
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;


    // min heap
    priority_queue<int, vector<int> , greater<int> > minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.top() << endl;


}