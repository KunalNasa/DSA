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
bool isCircular(Node* &head)
{
    if(head == NULL)
    {
        return true;
    }
    if(head->next == head)
    {
        return true;
    }
    Node* temp = head->next;
    while(temp != head && temp != NULL)
    {
        temp = temp->next;
    }
    if(temp == head)
    {
        return true;
    }
    return false;
}
// int getlength(Node* head)
// {
//     Node* temp = head->next;
//     int len = 1;
//     while(temp != head) 
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }
};
int main()
{


}