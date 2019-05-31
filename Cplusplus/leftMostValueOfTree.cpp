// Given a binary tree, find the leftmost value in the last row of the tree.

#include <vector>
#include <queue>
#include <limits>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int leftmost = root->val;

        while (!q.empty())
        {
            int size = q.size();
            leftmost = q.front()->val;

            while (size)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
                size--;
            }
        }
        return leftmost;
    }
};