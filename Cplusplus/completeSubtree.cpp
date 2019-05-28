/**
 * Return the largest subtree that is complete.
 *
 * Full Binary Tree: A Binary Tree is full if every node has 0 or 2 children. 
 * Complete Subtree: A Binary Tree is complete Binary Tree if all levels are 
 *          completely filled except possibly the last level and the last level has all keys as left as possible 
 * Perfect Binary Tree: A Binary tree is Perfect Binary Tree in which all
 *          internal nodes have two children and all leaves are at the same level.
 */

#include <vector>
#include <math.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct SubtreeData
{
    bool isPrefect;
    bool isComplete;
    int size;
    TreeNode *rootNode;
};

int height(int size)
{
    // Height of binary tree give the number of nodes
    return std::ceil(std::log2(size + 1));
}

void inorder(TreeNode *root, std::vector<int> &retval)
{
    if (root)
    {
        inorder(root->left, retval);
        retval.emplace_back(root->val);
        inorder(root->right, retval);
    }
}

SubtreeData helper(TreeNode *root)
{
    SubtreeData st;
    if (root == nullptr)
    {
        st.isPrefect = false;
        st.isComplete = false;
        st.size = 0;
        st.rootNode = nullptr;
        return st;
    }

    SubtreeData leftst = helper(root->left);
    SubtreeData rightst = helper(root->right);

    /**
     * CASE 1
     * 
     * If left subtree is perfect and right subtree is complete
     * and both subtrees are at same level then subtree root is complete
     * And size is one more than sum of sizes of both subtrees
     * And rootNode is the current node
     */
    if (leftst.isPrefect && rightst.isComplete && height(leftst.size) == height(rightst.size))
    {
        st.isPrefect = rightst.isPrefect;
        st.isComplete = true;
        st.size = leftst.size + rightst.size + 1;
        st.rootNode = root;
        return st;
    }

    /**
     * CASE 2
     * 
     * If left subtree is complete and right subtree is perfect
     * and left subtree is one level deeper than right subtree 
     * then subtree root is complete.
     * And size is one more than sum of sizes of both subtrees
     * And rootNode is the current node
     */
    if (leftst.isComplete && rightst.isPrefect && height(leftst.size) == height(rightst.size) + 1)
    {
        st.isPrefect = false;
        st.isComplete = true;
        st.size = leftst.size + rightst.size + 1;
        st.rootNode = root;
        return st;
    }

    /**
     * CASE 3
     * 
     * This subtree cannot be largest complete binary tree
     * Return largest left or right binary subtree
     */
    st.isPrefect = false;
    st.isComplete = false;
    st.size = std::max(leftst.size, rightst.size);
    st.rootNode = leftst.size > rightst.size ? leftst.rootNode : rightst.rootNode;
    return st;
}

std::vector<int> largestSubtree(TreeNode *root)
{
    std::vector<int> retval;

    SubtreeData st = helper(root);

    inorder(st.rootNode, retval);
    return retval;
}