/**
 * Given a binary search tree,
 * write a function kthSmallest to find the kth smallest element in it.
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
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        helper(root, k, ans);
        return ans;
    }

private:
    void helper(TreeNode *node, int &k, int &ans)
    {
        if (node == nullptr)
        {
            return;
        }

        if (k > 0)
        {
            helper(node->left, k, ans);
        }

        k--;

        if (k == 0)
        {
            ans = node->val;
            return;
        }

        if (k > 0)
        {
            helper(node->right, k, ans);
        }
    }
};