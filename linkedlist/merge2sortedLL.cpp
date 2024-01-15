#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void mergeTwoSortedLL(Node* headone, Node* headtwo)
{
    Node* first = headone;
    Node* second = headtwo;
    Node* mainListHead = new Node(-1);
    Node* temp = mainListHead;
    while(first != NULL && second != NULL)
    {
        if(first->data < second->data)
        {
            mainListHead->next = first;
            first = first->next;
            mainListHead = mainListHead->next;
        }
        else
        {
            mainListHead->next = second;
            second = second->next;
            mainListHead = mainListHead->next;
        }
    }

    while(first != NULL)
    {
        mainListHead->next = first;
        first = first->next;
        mainListHead = mainListHead->next;
    }

    while(second != NULL)
    {
        mainListHead->next = second;
        second = second->next;
        mainListHead = mainListHead->next;
    }
    Node * head = temp->next;
    delete temp;
}

 
int main()
{
    
}