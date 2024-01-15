#include<iostream>
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

void sortLinkedList(Node* head)
{
    int zero = 0, one = 0, two = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }  
        temp = temp->next;
    }
    temp = head;
    
    while(temp != NULL)
    {
        if(zero != 0)
        {
            temp->data = 0;
            zero--;
        }

        else if(one != 0)
        {
            temp->data = 1;
            one--;
        }

        else 
        {
            temp->data = 2;
        }
        temp = temp->next;
    }
}

void insert(Node* temp, Node* &tail)
{
    tail->next = temp;
    tail = temp;
}

void sortingLL(Node* head)
{
    // Node * temp = head;
    // while(temp->next  != NULL)
    // {
    //     if(temp->next->data < temp->data)
    //     {
    //         swap(temp->data, temp->next->data);
    //     }
    //     temp = temp->next;
    // }

    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onetail = onehead;
    Node* twotail = twohead;
    
    Node* temp =  head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            insert(temp, zerotail);
        }
        if(temp->data == 1)
        {
            insert(temp, onetail);
        }
        if(temp->data == 2 )
        {
            insert(temp, twotail);
        }

        temp = temp->next;
    }
    if(onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }

    twotail->next = NULL;

}
using namespace std;
int main()
{
    
}