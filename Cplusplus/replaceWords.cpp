/*
In English, we have a concept called root, 
which can be followed by some other words to form another longer word - let's call this word successor. 
For example, the root an, followed by other, which can form another word another.
Now, given a dictionary consisting of many roots and a sentence.
You need to replace all the successor in the sentence with the root forming it.
If a successor has many roots can form it, replace it with the root with the shortest length.
You need to output the sentence after the replacement.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord ( false ) {}
};



string replaceWords(vector<string>& dict, string sentence, TrieNode* root);
void printTrie( TrieNode* root );

int main(int argc, char const *argv[])
{
    TrieNode* root = new TrieNode();
    // root->isWord = false;
    // unordered_map<string, bool> isWord;

    vector<string> dict = { "cat", "bat", "rat" };
    string sentence = "the cattle was rattled by the battery";

    cout << replaceWords( dict, sentence, root ) << "." << endl;

    return 0;
}

string replaceWords(vector<string>& dict, string sentence, TrieNode* root)
{
    for ( string word : dict )
    {
        TrieNode* curr = root;

        for ( char c : word )
        {
            if ( !curr->children.count( c ) )
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }

    cout << "Printing Trie" << endl;
    printTrie( root );

    stringstream ss( sentence );
    string word;

    string result = "";

    while( ss >> word )
    {
        auto curr = root;
        string tempWord = "";
        for ( char c : word )
        {
            // If children doesn't exist then break;
            if ( !curr->children.count( c ) )
            {
                break;
            }
            if ( curr->children[c]->isWord )
            {
                word = tempWord + c;
                break;
            }
            tempWord += c;
            curr = curr->children[c];
        }

        result += word + " ";
    }
    return result.substr(0, result.length() - 1 );
}

void printTrie( TrieNode* root )
{
    if ( root->children.size() == 0 )
    {
        cout << endl;
        return;
    }

    for ( auto it : root->children )
    {
        cout << it.first;
        printTrie( it.second );
    }
}