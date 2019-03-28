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