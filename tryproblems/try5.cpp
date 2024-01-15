#include<iostream>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26]; //array of pointers to trienode objects 
    bool isTerminal;

    TrieNode(char ch)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false; 
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // The "Util" suffix is commonly used in function names to indicate that the function is a 
    // utility or helper function that assists in a larger operation or algorithm.
    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // if already present 
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            // absent case
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // RECURSIVE CALL
        insertUtil(child, word.substr(1));
        //substr(1) will pass the string from index 1 to ending index 
        // it is a function of string class
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void printSuggestions(vector<string> &temp, string prefix, TrieNode* curr)
    {
        if(curr -> isTerminal)
        {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr -> children[ch - 'a'];
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(temp, prefix, next);
                prefix.pop_back();
            }
        }
    }
    void getSuggestions(string str)
    {
        TrieNode* prev = root;
        vector<vector<string> > ans;
        string prefix = "";

        for(int i = 0; i < str.length(); i++)
        {
            char lastch = str[i] - 'a';

            TrieNode* curr = prev -> children[lastch];

            if(curr == NULL)
            {
                break;
            }
            
            vector<string> temp;
            printSuggestions(temp, prefix, curr);
            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }


    }
   
};
vector<vector<int> > phoneDir(vector<string> contactList, string query)
{
    Trie* t = new Trie();
    for(int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t -> insertWord(str);
    }
}
int main()
{
    
}