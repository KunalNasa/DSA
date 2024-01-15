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
};

void insertatHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertatTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
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
void insertatPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertatHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last position
    if (temp->next == NULL)
    {
        insertatTail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}
void deleteAtPosition(Node *&head,Node* &tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;  
        delete temp;
    }
    else
    {
        Node *current = head;
        Node *prev = head;
        int cnt = 1;
        while (cnt != position - 1)
        {
            prev = prev->next;
            cnt++;
        }
        current = prev->next;
        if(current->next == NULL)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    // created a new node
    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node 1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertatTail(tail, 12);

    print(head);

    insertatTail(tail, 15);

    print(head);

    insertatPosition(tail, head, 4, 24);
    print(head);

    cout << "Head " << head->data << ", tail " << tail->data << endl;

    deleteAtPosition(head, tail,4);
    print(head);
    deleteAtPosition(head,tail, 1);
    print(head);

    cout << "Head " << head->data << ", tail " << tail->data << endl;
 
}