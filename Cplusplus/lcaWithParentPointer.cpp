/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 */

#include <algorithm>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int depth(TreeNode *node)
{
    int depth = 0;
    while (node)
    {
        node = node->parent;
        depth++;
    }
    return depth;
}

TreeNode *lowestCommonAncestor(TreeNode *p, TreeNode *q)
{
    TreeNode *itr1 = p;
    TreeNode *itr2 = q;

    int d1 = depth(itr1);
    int d2 = depth(itr2);

    if (d1 < d2)
    {
        std::swap(itr1, itr2);
    }

    int diff = std::abs(d1 - d2);

    while (diff-- > 0)
    {
        itr1 = itr1->parent;
    }

    while (itr1 != itr2)
    {
        itr1 = itr1->parent;
        itr2 = itr2->parent;
    }

    return itr1;
}