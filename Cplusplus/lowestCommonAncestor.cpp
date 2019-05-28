/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
 * that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (p->val == root->val || q->val == root->val)
    {
        return root;
    }

    TreeNode *leftval = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightval = lowestCommonAncestor(root->right, p, q);

    if (leftval && rightval)
    {
        return root;
    }

    return leftval != nullptr ? leftval, rightval;
}