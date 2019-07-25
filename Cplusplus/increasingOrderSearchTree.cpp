/**
 * Given a binary search tree, rearrange the tree in in-order
 * so that the leftmost node in the tree is now the root of the tree,
 * and every node has no left child and only 1 right child.
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
private:
    TreeNode *curr;
    void helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        helper(node->left);
        node->left = nullptr;
        curr->right = node;
        curr = node;
        helper(node->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *ans = new TreeNode(0);
        curr = ans;

        helper(root);
        return ans->right;
    }
};