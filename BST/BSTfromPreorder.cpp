#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Node
{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int data)
    {
        this -> left = NULL;
        this -> right = NULL;
        this -> data = data;
    }
};

Node* buildFromPre(vector<int> &preorder, int mini, int maxi, int &index)
{
    if(index >= preorder.size())
    {
        return NULL;
    }
    if(preorder[index] > maxi || preorder[index] < mini)
    {
        return NULL;
    }

    Node* root = new Node(preorder[index++]);
    root -> left = buildFromPre(preorder, mini, root -> data, index);
    root -> right = buildFromPre(preorder, root -> data, maxi, index);

    return root;
}
void inorderTrav(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorderTrav(root -> left);
    cout << root -> data << " ";
    inorderTrav(root -> right);
}
int main()
{
    vector<int> preorder;
    preorder.push_back(10);
    preorder.push_back(7);
    preorder.push_back(5);
    preorder.push_back(8);
    preorder.push_back(15);
    preorder.push_back(12);
    int index = 0;
    Node* ans = buildFromPre(preorder, INT_MIN, INT_MAX, index);

    inorderTrav(ans);
    

}