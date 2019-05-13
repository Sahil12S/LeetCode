/*
Serialization is the process of converting a data structure or object 
into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed 
later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree.
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to 
a string and this string can be deserialized to the original tree structure.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelp( TreeNode* root, string& result )
    {
        if( root == nullptr )
        {
            result += "null ";
        }
        else
        {
            result += to_string( root->val ) + " ";
            serializeHelp( root->left, result );
            serializeHelp( root->right, result );
        }
    }
    
    TreeNode* deserializeHelp( stringstream& ss )
    {
        string node;
        ss >> node;
        if( node == "null" )
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode( stoi( node ) );
        root->left = deserializeHelp( ss );
        root->right = deserializeHelp( ss );
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelp( root, result );
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss( data );
        return deserializeHelp( ss );
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));