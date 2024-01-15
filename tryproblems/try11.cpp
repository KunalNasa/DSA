#include<iostream>
#include<queue>
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
Node* deleteLast(Node * &head)
{
    Node* curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr = NULL;
    // delete curr;
    return head;
}
int main()
{
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = deleteLast(head);
    cout << head->data <<endl;
    cout << head->next ->data <<endl;
    cout << head->next -> next -> data <<endl;

    queue<Node*> q;
    
}