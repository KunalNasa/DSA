#include<iostream>
#include<stack>
using namespace std;


class Stack
{
    public:
    int *arr;
    int top;
    int size;
    
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack overflow " << endl;
        }
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow " << endl;
        }
    }

    int peak()
    {
        if(top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    /*
    stack <int> s;
    s.push(2);
    s.push(3);
    s.pop();
    cout << "peak element is " << s.top() << endl;
    cout << "is stack empty ? " << s.empty() << endl;
    */
   Stack st(5);
   st.push(20);
   st.push(40);
   st.push(60);
   st.push(80);
   st.push(100);
   st.push(120);


   cout << st.peak() << endl;
   st.pop();
   cout << st.peak() << endl;
   st.pop();
   cout << st.peak() << endl;
   st.pop();
   cout << st.peak() << endl;
   st.pop();
   cout << st.peak() << endl;
   cout << st.isEmpty() << endl;



}