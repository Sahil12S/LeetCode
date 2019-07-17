/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 */

#include <vector>
#include <unordered_map>

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
    std::unordered_map<int, int> inorderNodeIdx;

    TreeNode *helper(std::vector<int> &preorder, int preIdxStart, int preIdxEnd,
                     int inIdxStart, int inIdxEnd)
    {
        if (preIdxStart >= preIdxEnd || inIdxStart >= inIdxEnd)
        {
            return nullptr;
        }

        int root_val = preorder[preIdxStart];
        TreeNode *root = new TreeNode(root_val);

        int index = inorderNodeIdx.at(root_val);
        int left_subtree_size = index - inIdxStart;

        root->left = helper(preorder, preIdxStart + 1, preIdxStart + 1 + left_subtree_size, inIdxStart, index);
        root->right = helper(preorder, preIdxStart + 1 + left_subtree_size, preIdxEnd, index + 1, inIdxEnd);

        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderNodeIdx[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size(), 0, inorder.size());
    }
};