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



void insertAtTail(Node* &anshead, Node* &anstail, int digit)
    {
        Node * temp = new Node(digit);
        
        if(anshead == NULL)
        {
            anshead = temp;
            anstail = temp;
            return;
        }
        else
        {
            anstail -> next = temp;
            anstail = temp;
        }
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
    
    Node* add(Node* first, Node* second)
    {
        int carry = 0;
        Node* anshead = NULL;
        Node* anstail = NULL;
        
        while(first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
            
            int val2 = 0;
            if(second != NULL)
                val2 = second -> data;
                
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(anshead, anstail, digit);
            
            if(first != NULL)
            {
                first = first -> next;
            }
            
            if(second != NULL)
            {
                second = second -> next;
            }

        }
        
        return anshead;
    }
    //Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second)
    {
        first = reverseLL(first);
        second = reverseLL(second);
        
        Node* sum = add(first, second);
        
        sum = reverseLL(sum);
        
        return sum;
    }
int main()
{
    
}