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

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            return root -> isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            //absent
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    int deleteUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            if(root -> isTerminal == true)
            {
                root -> isTerminal = false;
                return 1;
            }
            else
            {
                cout << "Can not delete the word. It is not present in the trie" << endl;
                return -1;
            }
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            return -1;
        }

        int result =  deleteUtil(child, word.substr(1));

        if(child -> isTerminal == false)
        {
            delete child;
            root -> children[index] = NULL;
        }
        return result;
    }

    int deleteWord(string word)
    {
        return deleteUtil(root, word);
    }
};
int main()
{
    Trie* t = new Trie();

    t->insertWord("ARMS");
    t->insertWord("DO");

    cout <<"Present or Not " << t->search("ARM") << endl;

    cout << t->deleteWord("ARMS") << endl;

    cout << t->deleteWord("ARM") << endl;

    cout << t->deleteWord("AM") << endl;

    cout << t->deleteWord("DO") << endl;

    cout << t->deleteWord("DO") << endl;

}