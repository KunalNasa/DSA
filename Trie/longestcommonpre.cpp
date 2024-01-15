#include<iostream>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie
{
    public:
    TrieNode* root;
    Trie(char ch) 
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    
    void longestCommonPrefix(string word, string &ans)
    {
        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            // the first child count would be of root node with null character
            if(root -> childCount == 1)
            {
                ans.push_back(ch);

                // moving ahead to next alphabet
                int index = word[i] - 'a';
                root = root -> children[index];
            }
            else
            {
                break;
            }

            if(root -> isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie('\0');
    for(int i = 0; i < n; i++)
    {
        t ->insertWord(arr[i]);
    }
    string word = arr[0];
    string ans = "";
    t -> longestCommonPrefix(word, ans);
    return ans;
}


int main()
{
    vector<string> str;
    str.push_back("geeks");
    str.push_back("geekforgeeks");
    str.push_back("geek");
    str.push_back("geekisgeesk");

    cout << longestCommonPrefix(str, 4);

}