/*
Implement a MapSum class with insert, and sum methods.
For the method insert, you'll be given a pair of (string, integer).
The string represents the key and the integer represents the value.
If the key already existed, then the original key-value pair will be overridden to the new one.
For the method sum, you'll be given a string representing the prefix,
and you need to return the sum of all the pairs' value whose key starts with the prefix.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int val;
        
        TrieNode( int val ) : val ( val ) {}
    };
    
    TrieNode* root;
    
    unordered_map<string, int> map;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode( 0 );
        
    }
    
    void insert(string key, int val) {
        int delta = val - ( map.count( key ) ? map[key] : 0 );
        map[key] = val;
        
        TrieNode* curr = root;
        curr->val += delta;
        
        for ( char c : key )
        {
            if ( !curr->children.count( c ) )
            {
                curr->children[c] = new TrieNode( 0 );
                // curr->chil
            }
            curr = curr->children[c];
            curr->val += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        
        for ( char c : prefix )
        {
            if ( !curr->children.count( c ) )
            {
                return 0;
            }
            curr = curr->children[c];
        }
        
        return curr->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(int argc, char const *argv[])
{
    MapSum* obj = new MapSum();

    obj->insert( "apple", 3 );
    cout << obj->sum( "ap" ) << endl;
    obj->insert( "app", 2 );
    cout << obj->sum( "ap" ) << endl;

    return 0;
}
