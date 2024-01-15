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

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(head != NULL && head->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node* merge(Node* left, Node* right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
    Node* first = left;
    Node* second = right;
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

    return head;
}
Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // sort left part
    left = mergeSort(left);

    // sort right part 
    right = mergeSort(right);

    merge(left, right);

}
int main()
{
    
}