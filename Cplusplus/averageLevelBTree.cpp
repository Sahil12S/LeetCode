// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if ( root == nullptr )
        {
            return ans;
        }
        
        queue<TreeNode*> Q;
        int level = 0;
        
        Q.push( root );
        
        while ( !Q.empty() )
        {
            ans.push_back(0);
            int l_length = Q.size();
            
            for ( int i = 0; i < l_length; i++ )
            {
                if ( Q.front()->left )
                    Q.push( Q.front()->left );
                if ( Q.front()->right )
                    Q.push( Q.front()->right );
                
                ans[level] += Q.front()->val;
                Q.pop();
            }
            ans[level] /= l_length;
            level++;
        }
        
        return ans;
    }
};