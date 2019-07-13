/**
 * Given a binary tree, find the length of the longest increasing consecutive sequence path.
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections.
 * The longest increasing consecutive path need to be from parent to child (cannot be the reverse).
 */

#include <algorithm>

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
private:
    int helper(TreeNode *node, TreeNode *parent, int len)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (parent && node->val - parent->val == 1)
        {
            len++;
        }
        else
        {
            len = 1;
        }
        return std::max(len, std::max(helper(node->left, node, len), helper(node->right, node, len)));
    }

public:
    int longestConsecutive(TreeNode *root)
    {
        return helper(root, nullptr, 0);
    }
};