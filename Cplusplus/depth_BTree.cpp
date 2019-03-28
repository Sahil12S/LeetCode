// Given a binary tree, you need to compute the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
// This path may or may not pass through the root.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    int maxD = 0;

    void maxDia( TreeNode* root )
    {
        if ( root == nullptr )
        {
            return 0;
        }

        int lHeight = maxDia( root->left );
        int rHeight = maxDia( root->right );

        maxD = max( maxD, l + r + 1 );
        return max( l, r ) + 1;
    }

public:
    int diameterOfBinaryTree( TreeNode* root )
    {
        maxD = 1;

        maxDia( node );
        
        return maxD - 1;
    }
};