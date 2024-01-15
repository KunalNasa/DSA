#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* arb;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};

// void insertAtTail(Node* &head, Node* &tail, int d)
// {
//     Node* data = new Node(d);
//     if(head == NULL)
//         {
//             head = data;
//             tail = data;
//         }
//         else
//         {
//             tail->next = data;
//             tail = data;
//         }
// }
// Node* cloneaLL(Node* head)
// {
//     Node* clonetail = NULL;
//     Node* clonehead = NULL;
//     Node* temp = head;
//     while(temp != NULL)
//     {
//         insertAtTail(clonehead, clonetail, temp->data);
//         temp = temp->next; 
//     }

//     unordered_map<Node*, Node*> oldToNewNode;
//     Node* originalNode = head;
//     Node* cloneNode = clonehead;
//     while(originalNode != NULL)
//     {
//         oldToNewNode[originalNode] = cloneNode;
//         originalNode = originalNode->next;
//         cloneNode = cloneNode->next;
//     }
//     Node* originalNode = head;
//     Node* cloneNode = clonehead;
//     while(originalNode != NULL)
//     {
//         cloneNode->arb = oldToNewNode[originalNode->arb];
//         originalNode = originalNode->next;
//         cloneNode = cloneNode->next;
//     }

//     return clonehead;
// }
void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
Node* copyList(Node* head)
{
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = NULL;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    unordered_map<Node*, Node*> originalToCopy;

    Node* originalNode = head;
    Node* copyNode = cloneHead;

    while(originalNode != NULL)
    {
        originalToCopy[originalNode] = copyNode;
        originalNode = originalNode->next;
        copyNode = copyNode->next;
    }
    originalNode = head;
    copyNode = cloneHead;
    while(originalNode != NULL)
    {
        copyNode->arb = originalNode->arb;
        originalNode = originalNode->next;
        copyNode = copyNode->next;
    }

    return cloneHead;
}
int main()
{
        
}