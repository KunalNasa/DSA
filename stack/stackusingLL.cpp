#include<iostream>
using namespace std;
class Node
{
    public:
    Node* next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    public:
    Node* tail;
    Node* head;

    Stack()
    {
        tail = new Node(-1);
        head = tail;
    }
    void push(int data)
    {
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;  
    }

    void pop()
    {
        if(head == tail)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            Node* temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
        }
    }

    int peak()
    {
        if(head == tail)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return tail->data;
        }
        
    }

    bool isEmpty()
    {
        if(head == tail)
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
    Stack st;
    st.push(5); 
    st.push(10);
    st.push(15);

    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;
    st.pop();
    cout << st.peak() << endl;

}