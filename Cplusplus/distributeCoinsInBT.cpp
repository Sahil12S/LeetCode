/**
 * Given the root of a binary tree with N nodes,
 * each node in the tree has node.val coins, and there are N coins total.
 * In one move, we may choose two adjacent nodes and move one coin from one node to another.
 * (The move may be from parent to child, or from child to parent.)
 * Return the number of moves required to make every node have exactly one coin.
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
    int ans = 0;

    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int L = dfs(node->left);
        int R = dfs(node->right);
        ans += std::abs(L) + std::abs(R);
        return node->val + L + R - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};