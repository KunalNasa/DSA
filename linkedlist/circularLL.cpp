#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next  = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};
void insertNode(Node *&tail, int data, int element)
{
    // empty list
    if (tail == NULL)
    {
        Node *firstNode = new Node(data);
        tail = firstNode;
        tail->next = tail;
    }
    else
    {
        // non empty list assuming that element is present there
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node * tail)
{
    Node * temp = tail;
    // empty list
    if(tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
    cout<< endl;
}

void deleteNode(Node* &tail, int value)
{
    // empty list
    if(tail == NULL)
    {
        cout << "List is empty. please insert some elements" << endl;
    }
    else
    {
        //non empty
        // assuming that value is present in the linked list
        Node * prev = tail;
        Node* curr = prev->next; 
        if(curr == prev)
        {
            tail = NULL;
        }
        while(curr->data != value)
        {
            curr = curr->next;
            prev = prev->next;
        }
        // 2 node linked list
        if(tail == curr)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node * tail = NULL;
    insertNode(tail, 4, 5);
    print(tail);
    /*
    insertNode(tail,10, 4);
    print(tail);
    insertNode(tail, 13, 4);
    print(tail);
    insertNode(tail, 40, 10);
    print(tail);
    */
    deleteNode(tail, 4);
    print(tail); 


}