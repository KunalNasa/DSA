#include<iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void removeDuplicates(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }

        // not equal
        curr = curr->next;
    } 
}

void removeDuplicateUnsortedLL(Node* head)
{
    Node * curr = head;
    while(curr->next != NULL)
    {
        Node* temp = curr->next;
        Node* prev = curr;
        while(temp != NULL)
        {
            if(temp->next == curr)
            {
                Node* todelete = temp->next;
                temp->next = temp->next->next;
                todelete->next = NULL;
                delete todelete;
            }
            else
            {
                prev = prev->next;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}
int main()
{
    
}