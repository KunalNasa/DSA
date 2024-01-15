#include <iostream>
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
Node *reverseInKgroups(Node *&head, int k)
{
    // base case
    if(head == NULL)
        {
            return head;
        }
        
        int count = 0;
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr && count < k)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        
        if(forward)
            head -> next = reverseInKgroups(forward, k);
        
        return prev;
}
int main()
{
}