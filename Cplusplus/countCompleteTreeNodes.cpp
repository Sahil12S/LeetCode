/**
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note:
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level are as far left as possible.
 * It can have between 1 and 2h nodes inclusive at the last level h.
 */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    int count = 0;

public:
    int countNodes(TreeNode *root)
    {
        if (root)
        {
            count++;
            countNodes(root->left);
            countNodes(root->right);
        }
        /**
            if(!root)
            {
                return 0;
            }

            queue<TreeNode*> q;
            q.push(root);
            int count = 0;
            while(!q.empty())
            {
                int s = q.size();
                while(s--)
                {
                    TreeNode* curr = q.front();
                    q.pop();

                    count++;

                    if(curr->left)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right)
                    {
                        q.push(curr->right);
                    }
                }
            }
        */
        return count;
    }
};