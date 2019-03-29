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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int>> ans;
        
        if ( !root )
        {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push( root );
        int level = 0;
        
        while ( !q.empty() )
        {
            ans.push_back( {} );
            int l = q.size();
            
            for ( int i = 0; i < l; i++ )
            {
                if ( q.front()->left )
                    q.push( q.front()->left );
                if ( q.front()->right )
                    q.push( q.front()->right );
                
                ans[level].push_back(q.front()->val);
                
                q.pop();
            }
            if ( level % 2 == 1 )
            {
                reverse( ans[level].begin(), ans[level].end() );
            }
            level++;
        }
        return ans;
        
    }
};