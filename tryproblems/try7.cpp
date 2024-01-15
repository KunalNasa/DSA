#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}
class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index / 2;
            if(arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        arr[1] = arr[size];
        size--;
        for(int i = size / 2; i > 0; i--)
            heapify(arr, size, i);
    }

    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    heap h;
    h.insert(10);
    h.insert(25);
    h.insert(30);
    h.insert(5);
    h.insert(22);

    h.print();
    cout << endl;

    h.deleteFromHeap();

    h.print();
    cout << endl;
}