// Delete a node from BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        {
            return root;
        }
        
        if ( key < root->val )
        {
            root->left = deleteNode( root->left, key );
        }
        else if ( key > root->val )
        {
            root->right = deleteNode( root->right, key );
        }
        else
        {
            if ( root->left == nullptr )
            {
                auto temp = root->right;
                delete root;
                return temp;
            }
            if ( root->right == nullptr )
            {
                auto temp = root->left;
                delete root;
                return temp;
            }
            
            auto temp = root->right;
            while ( temp->left )
            {
                temp = temp->left;
            }
            root->val = temp->val;
            
            root->right = deleteNode( root->right, temp->val );
        }
        return root;
    }
};