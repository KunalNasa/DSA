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

Node* FloydCycle(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* fast = head;
    Node* slow = slow->next;
    while(fast != NULL && slow != NULL)
    {
    fast = fast->next;
    if(fast != NULL)
    {
        fast = fast->next;
    }
  
    if(fast == slow)
    {
        return slow;
        cout << "Loop is found at element " << slow << endl;
    }
    }
    return NULL;
}

Node* beginningOfLoop(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* startOfLoop = FloydCycle(head);
    Node* slow = head;
    while(slow != startOfLoop)
    {
        slow = slow->next;
        startOfLoop = startOfLoop->next;
    }
    return startOfLoop;

}

void removeLoop(Node* head)
{
    Node* start = beginningOfLoop(head);
    Node* temp = start;
    while(temp->next != start)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}
int main()
{
    
}