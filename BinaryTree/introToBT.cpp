#include<iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }

};
Node* buildTree(Node* root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data <<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root)   
{
    queue <Node*> q;
    q.push(root);
    q.push(NULL); // inserting separator after first level

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) //purana Node complete traverse ho chuka hai
        {
            cout << endl;
            if(!q.empty()) // queue still has some child nodes
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
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        
    }

}

void reverseOrderTrav(Node* root)
{
    queue <Node*> q;
    stack <Node*> st;
    q.push(root);
    st.push(root);
    q.push(NULL);
    st.push(NULL); // inserting separator after first level

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) //purana Node complete traverse ho chuka hai
        {
            if(!q.empty()) // queue still has some child nodes
            {
                q.push(NULL);
                st.push(NULL);
            }
        }
        else
        {  
            if(temp->right)
            {
                q.push(temp->right);
                st.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
                st.push(temp->left);
            }
        }        
    }
        while(!st.empty())
        {
            if(st.top() == NULL)
            {
                cout << endl;
            }
            else
            {
                Node * temp = st.top();
                cout << temp -> data << " ";
            }
            st.pop();
        }

}
void inOrder(Node* root)
{
    //LNR
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(Node * &root)
{
    queue<Node*> q;

    int data;
    cout << "enter data for node " << endl;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left of : " << temp->data << endl;
        cin >> leftData;

        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of : " << temp->data << endl; 
        cin >> rightData;

        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}
int main()
{
    Node* root = NULL;

    root = buildTree(root);
    // buildFromLevelOrder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);
    cout << endl;
    // reverseOrderTrav(root);

    inOrder(root);
    
    // cout << endl;

    // preOrder(root);

    // cout << endl;

    // postOrder(root);

    //1 2 4 -1 -1 5 -1 -1 3 -1 6 7 -1 -1 -1

}