/**
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from
 * some starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 */
#include <algorithm>
#include <limits>

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
    int max_val = std::numeric_limits<int>::min();

    long helper(TreeNode *node)
    {
        if (!node)
        {
            return std::numeric_limits<int>::min();
        }

        // Get max value from left subtree
        long leftval = helper(node->left);

        // Get max value from right subtree
        long rightval = helper(node->right);

        // Check what makes current max
        // If its node + left side or node + right side or just node
        long curr_max = std::max(
            leftval + node->val,
            std::max(
                rightval + node->val,
                static_cast<long>(node->val)));

        // Max value could either be current max or left + right + itself
        max_val = std::max(max_val, static_cast<int>(std::max(node->val + leftval + rightval, curr_max)));

        return curr_max;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int curr_max = helper(root);
        return max_val;
    }
};