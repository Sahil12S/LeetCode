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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        
        vector< vector<int>> ans;
        vector<int> vals;
        queue<TreeNode*> q;
        
        queue<int> level;
        int l = 0;
        
        q.push(root);
        level.push(1);
        
        TreeNode* curr;
        
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            level.front()--;
            vals.emplace_back(curr->val);
            
            if (level.front() == 0 && vals.size())
            {
                ans.emplace_back(vals);
                vals.clear();
            }
            
            if (curr->left)
            {
                q.push(curr->left);
                l++;
            }
            if (curr->right)
            {
                q.push(curr->right);
                l++;
            }
            
            if (l && level.front() == 0)
            {
                level.push(l);
                level.pop();
                l = 0;
            }
        }
        
        if (vals.size())
        {
            ans.emplace_back(vals);
        }
        
        return ans;
    }
};

/** Version 2 **/

class Solution {
private:
    vector<vector<int>> ans;
    
    void helper( TreeNode* root, int level )
    {
        if( ans.size() == level )
        {
            ans.push_back( {} );
        }
        
        ans[level].push_back( root-> val );
        
        if ( root->left )
        {
            helper( root->left, level + 1 );
        }
        if ( root->right )
        {
            helper( root->right, level + 1 );
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if ( root == nullptr )
        {
            return ans;
        }
        
        helper( root, 0 );
        return ans;
    }
};

/** Version 3 **/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int>> ans;
        
        if ( root == nullptr )
        {
            return ans;
        }
        
        queue<TreeNode*> q;
        
        int level = 0;
        
        q.push(root);
        
        while ( !q.empty() )
        {
            ans.push_back( {} );
            
            int l_length = q.size();
            
            for ( int i = 0; i < l_length; i++ )
            {
                auto temp = q.front();
                q.pop();
                
                ans[level].push_back( temp->val );
                
                if ( temp->left )
                    q.push( temp->left );
                if ( temp->right )
                    q.push( temp->right );
            }
            level++;
        }      
        return ans;
    }
};