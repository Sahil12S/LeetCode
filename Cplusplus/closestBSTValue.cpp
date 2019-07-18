/**
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 * 
 * Note:
 * 
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
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
public:
    int closestValue(TreeNode *root, double target)
    {
        double diff = std::numeric_limits<double>::max();
        int value = root->val;

        while (root != nullptr)
        {
            if (std::abs(root->val - target) < diff)
            {
                diff = std::abs(root->val - target);
                value = root->val;
            }
            if (diff <= 0.5)
                break;
            if (target < root->val)
            {
                root = root->left;
            }
            else if (target > root->val)
            {
                root = root->right;
            }
        }
        return value;
    }
};