#include<iostream>
using namespace std;
// creating a Node for linked list 

class Node
{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    // tail = tail -> next;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail,int position, int d)
{
    int cnt = 1;
    Node *temp = head;

    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    while (cnt != position - 1)
    {
        temp = temp -> next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
 

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


void print(Node* head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* firstnode = new Node(12);
    // cout << firstnode -> data << endl;
    // cout << firstnode -> next << endl;
    Node * head = firstnode;
    Node * tail = firstnode;

    // insertAtHead(head, 14);
    // print(head);
    // insertAtHead(head, 16);
    // print(head);

    insertAtTail(tail, 14);
    print(head);
    insertAtTail(tail, 16);
    print(head);
    insertAtPosition(head, tail, 1 , 15);
    print(head);
}