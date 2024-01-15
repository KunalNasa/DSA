#include<iostream>
#include <queue>
using namespace std;
class Node
{
    public:
    Node* right;
    Node* left;
    int data;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

void levelOrderTraversal(Node* &root)
{
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }  
    }
}
Node* constructBST(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    
    if(data > root->data)
    {
        //insert in right part
        root->right = constructBST(root->right, data);
    }
    else
    {
        // insert at left part
        root->left = constructBST(root->left, data);
    }
    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = constructBST(root, data);
        cin >> data;
    }
}
Node* maxVal(Node* root)
{
    Node* temp = root;
    while(temp -> right)
    {
        temp = temp -> right;
    }

    return temp;
}
Node* minVal(Node* root)
{
    Node* temp = root;
    while(temp -> left)
    {
        temp = temp -> left;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root -> data == val)
    {
        //0 child case
        if(root -> right == NULL && root -> left == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child case
        if(root -> right && !root -> left)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        if(!root -> right && root -> left)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> right != NULL && root -> left != NULL)
        {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val)
    {
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else
    {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main()
{
    Node* root = NULL;
    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    levelOrderTraversal(root);
}