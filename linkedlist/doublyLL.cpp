#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&tail, Node *&head, int data)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(tail, head, data);
        return;
    }
    Node *temp = head;
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }
    int cnt = 1;
    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;
    temp->next->prev = nodeToInsert;
}

void deleteAtPosition(Node* &head, int position)
{
    Node *temp = head;
    if (position == 1)
    {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
  
        int cnt = 1;
        while (cnt != position - 1)
        {
            temp = temp->next;
            cnt++;
        }

    Node *objToDelete = temp->next;
    if (objToDelete->next == NULL)
    {
        temp->next = NULL;
        objToDelete->prev = NULL;
        delete objToDelete;
        return;
    }
    temp->next = objToDelete->next;
    objToDelete->next->prev = temp;
    objToDelete->next = NULL;
    objToDelete->prev = NULL;

    delete objToDelete;
}
int main()
{
    // Node * firstNode = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    /*
    // To get length of the LL
    int length = getlength(head);
    cout << length << endl;
    */

    insertAtTail(tail, head, 25);
    print(head);
    insertAtTail(tail, head, 24);
    insertAtTail(tail, head, 27);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);
    print(head);
    insertAtPosition(head, tail, 30, 6);
    print(head);
    deleteAtPosition(head, 6);
    print(head);
}