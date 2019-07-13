/**
 * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

 * Especially, this path can be either increasing or decreasing.
 * For example, [1,2,3,4] and [4,3,2,1] are both considered valid,
 * but the path [1,2,4,3] is not valid. On the other hand,
 * the path can be in the child-Parent-child order,
 * where not necessarily be parent-child orde
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
    int max_val = 0;
    std::pair<int, int> helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }

        int incr = 1;
        int decr = 1;

        if (node->left)
        {
            std::pair<int, int> p = helper(node->left);
            if (node->val == node->left->val + 1)
            {
                decr = p.second + 1;
            }
            else if (node->val == node->left->val - 1)
            {
                incr = p.first + 1;
            }
        }
        if (node->right)
        {
            std::pair<int, int> p = helper(node->right);
            if (node->val == node->right->val + 1)
            {
                decr = std::max(decr, p.second + 1);
            }
            else if (node->val = node->right->val - 1)
            {
                incr = std::max(incr, p.first - 1);
            }
        }
        max_val = std::max(max_val, decr + incr - 1);
        return {incr, decr};
    }

public:
    int longestConsecutive(TreeNode *root)
    {
        helper(root);
        return max_val;
    }
};