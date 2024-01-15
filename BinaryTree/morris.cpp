#include<iostream>
#include <queue>
using namespace std;
class Node
{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void morrisTraversal(Node* root)
{
    while(root)
    {
        if (root -> left == NULL)
        {
            cout << root->data << " ";
            root = root -> right;
        }
        else
        {
            Node* current = root->left;
            while(current->right && current->right != root)
            {
                current = current->right;
            }

            if(current -> right == NULL)
            {
                current -> right = root;
                cout << root -> data << " ";
                root = root -> left;
                
            }
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
            else
            {
                // cout<< root -> data << " ";
                current->right = NULL;
                cout << root -> data << " ";
                root = root -> right;
               
            }
        }
        
    }
}

void constructTree()
{
   
    int rootData;
    cout << "Enter data for the root node " << " : ";
    cin >> rootData;
    if(rootData == -1)
    {
        return;
    }
    Node* root = new Node(rootData);

    queue <Node*> q; 
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left of " << temp->data << " : ";
        cin >> leftData;
        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        else
        {
            temp->left = NULL;
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " : ";
        cin >> rightData;
        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
        else
        {
            temp->right = NULL;
        }
    }
    morrisTraversal(root);
}

int main()
{
    constructTree();

}