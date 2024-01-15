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
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(data);
        tail = newnode;
        head = newnode;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        tail = newnode;
        head = newnode;
    }
    else
    {
        // new node create
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}
void insertNode(Node *&head, Node *tail, int data, int position)
{
    Node *temp = head;
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int cnt = 1;
    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
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

Node* reverseALinkedList(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward; 
    }
    return prev;
}
void reverserecursively(Node* head, Node* prev, Node* curr)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }

        Node* forward = curr->next;
        reverserecursively(head, curr, forward);
        curr->next = prev;
}

Node* reverse(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* chotahead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotahead;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 40);
    print(head);
   cout << reverseALinkedList(head) << endl;
    print(head);


}