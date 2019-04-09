/*
Implement a trie with insert, search, and startsWith methods.
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
    };
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        // Initialize root
        root = new TrieNode;
        
        // Root is not a complete word
        root->isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for ( char c : word )
        {
            if ( !curr->children.count( c ) )
            {
                // Add each character in trie
                curr->children[c] = new TrieNode;
                
                // Mark added character as not word
                curr->children[c]->isWord = false;
            }
            curr = curr->children[c];
            
        }
        // After adding the whole word, mark it as complete word.
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        
        for ( char c : word )
        {
            // If character is not in trie, return false
            if ( !curr->children.count( c ) )
            {
                return false;
            }
            curr = curr->children[c];
        }
        
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for ( char c : prefix )
        {
            if ( !curr->children.count( c ) )
            {
                return false;
            }
            curr = curr->children[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[])
{
    Trie* obj = new Trie();
    obj->insert( "apple" );

    cout << obj->search( "apple" ) << endl;
    cout << obj->search( "app" ) << endl;
    cout << obj->startsWith( "app" ) << endl;

    obj->insert( "app" );
    cout << obj->search( "app" ) << endl;

    return 0;
}
