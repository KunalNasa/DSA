#include<iostream>
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
void inTrav(Node* root, vector<int> &inorder)
    {
        if(root == NULL)
        {
            return;
        }
        
        inTrav(root -> left, inorder);
        inorder.push_back(root -> data);
        inTrav(root -> right, inorder);
    }
    Node* buildFromInorder(vector<int> &inorder, int s, int e)
    {
        if(s > e)
        {
            return NULL;
        }
        int mid = s + (e - s)/ 2;
        Node* root = new Node(inorder[mid]);
        root -> left = buildFromInorder(inorder, s, mid - 1);
        root -> right = buildFromInorder(inorder, mid + 1, e);
        
        return root;
    }
    Node* buildBalancedTree(Node* root)
    {
    	vector<int> inorder;
    	inTrav(root, inorder);
    	int s = 0;
    	int e = inorder.size() - 1;
    	Node* ans = buildFromInorder(inorder, s, e);
    	
    	return ans;
    }
int main()
{
    
}