// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int>> ans;
        if ( root == nullptr )
        {
            return ans;
        }
        
        queue<TreeNode*> Q;
        Q.push( root );
        int level = 0;
        
        while ( !Q.empty() )
        {
            ans.push_back( {} );
            int l_length = Q.size();
            
            for ( int i = 0; i < l_length; i++ )
            {
                auto temp = Q.front();
                Q.pop();
                ans[level].push_back( temp->val );
                
                if ( temp->left )
                    Q.push( temp->left );
                if ( temp->right )
                    Q.push( temp->right );
                
            }
            level++;
        }
        reverse( ans.begin(), ans.end() );
        return ans;
        
    }
};