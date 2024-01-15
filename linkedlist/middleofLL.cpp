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
        this->next = next;
    }
};
Node* middle(Node* &head)
{
    Node* pro = head;
    Node* noob = head;
    while(pro->next != NULL)
    {
        noob = noob->next;
        pro = pro->next->next;
    }
    return noob;
}

    Node * getmiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast -> next != NULL && fast != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow;
}
Node* reverseLL(Node* head)
{
        Node* temp = NULL;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL)
        {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
}
int main()
{       
}