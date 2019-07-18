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
        int value, closest_val = root->val;

        while (root != nullptr)
        {
            value = root->val;
            closest_val = abs(value - target) < abs(closest_val - target) ? value : closest_val;
            root = target < value ? root->left : root->right;
        }

        return closest_val;
    }
};