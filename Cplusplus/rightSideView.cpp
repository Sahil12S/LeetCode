// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** Version 1 **/
class Solution {
private:
    void helper( TreeNode* node, int level, int& maxL, vector<int>& ans )
    {
        if ( node == nullptr )
        {
            return;
        }

        if ( maxL < level )
        {
            ans.push_back( node->val );
            maxL = level;
        }

        helper( node->right, level+1, maxL, ans );
        helper( node->left, level+1, maxL, ans );
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxL = -1;
        helper( root, 0, maxL , ans);
        return ans;
    }
};

/** Version 2 **/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if ( !root )
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while ( !q.empty() )
        {
            int size = q.size();
            
            for ( int i = 1; i <= size; i++ )
            {
                auto temp = q.front();
                q.pop();
                
                if ( i == size )
                {
                    ans.push_back( temp->val );
                }
                
                if ( temp->left )
                {
                    q.push( temp->left );
                }
                if ( temp->right )
                {
                    q.push( temp->right );
                }
            }
        }
        
        return ans;
    }
};