#include <iostream>
#include <map>
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

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Loop is detected on element " << temp->data << endl;
            return 1;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}

Node* FloydCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Loop is present at " << slow->data;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node * intersection = FloydCycle(head);
    Node * slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    Node * startOfLoop = getStartingNode(head);
    Node * temp = startOfLoop;
    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL; 
}

int main()
{
    
}