// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root.
// Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

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
private:
    bool isLeaf( TreeNode* node )
    {
        if ( !node->left && !node->right )
        {
            return true;
        }
        return false;
    }
    
    void getLeftBoundary( TreeNode* node, vector<int>& ans )
    {
        if( node == nullptr )
        {
            return;
        }
        // cout << node->val << endl;
        if ( node->left )
        {
            // if ( !isLeaf( node ) )
            ans.push_back( node->val );
            getLeftBoundary( node->left, ans );
        }
        else if ( node->right )
        {
            // if ( !isLeaf( node ) )
            ans.push_back( node->val );
            getLeftBoundary( node->right, ans );
        }
    }
    
    void getRightBoundary( TreeNode* node, vector<int>& ans )
    {
        if ( node == nullptr )
        {
            return;
        }
        
        if ( node->right )
        {
            getRightBoundary( node->right, ans );
            // if ( !isLeaf( node ) )
            ans.push_back( node->val );
        }
        else if ( node->left )
        {
            getRightBoundary( node->left, ans );
            
            ans.push_back( node->val );
        }
    }
    
    void getLeaves( TreeNode* node, vector<int>& ans )
    {
        if ( node == nullptr )
        {
            return;
        }
        
        getLeaves( node->left, ans );
        
        if ( !node->left && !node->right )
        {
            ans.push_back( node->val );
        }
        
        getLeaves( node->right, ans );
        
        
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if ( root == nullptr )
        {
            return ans;
        }
        ans.push_back( root->val );
        getLeftBoundary( root->left, ans );
        getLeaves( root->left, ans );
        getLeaves( root->right, ans );
        getRightBoundary( root->right, ans );
        return ans;
    }
};