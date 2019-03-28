// Given a binary tree, flatten it to a linked list in-place.

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
    void flatten(TreeNode* root) {
        if ( root == nullptr || ( root->left == nullptr && root->right == nullptr ) )
        {
            return;
        }
        
        if ( root->left )
        {
            // Go to left most node
            flatten( root->left );
            
            // move left node to right side
            auto tempR = root->right;
            
            root->right = root->left;
            root->left = nullptr;
            
            // attach right subtree to right most node of current subtree
            auto it = root->right;
            while ( it->right )
            {
                it = it->right;
            }
            
            it->right = tempR;
        }
        
        // flatten the right side
        flatten( root->right );
    }
};