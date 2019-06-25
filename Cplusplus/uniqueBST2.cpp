#include <vector>

#define FORI(s, n) for (int i = s; i <= n; i++)
#define FORJ(s, n) for (int j = s; j <= n; j++)

using VI = std::vector<int>;

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
    std::vector<TreeNode *> tree_generator(int start, int end)
    {
        // cout << "start: " << start << " end: " << end << endl;
        std::vector<TreeNode *> trees;
        if (start > end)
        {
            trees.emplace_back(nullptr);
            return trees;
        }

        // Picking root one by one
        FORI(start, end)
        {
            // cout << "=> " << i << endl;

            // Find it's left subtree
            std::vector<TreeNode *> left_trees = tree_generator(start, i - 1);
            // Find it's right subtree
            std::vector<TreeNode *> right_trees = tree_generator(i + 1, end);

            // Add left and right nodes
            for (TreeNode *l : left_trees)
            {
                for (TreeNode *r : right_trees)
                {
                    // cout << "l: " << l << ", r: " << r << endl;
                    TreeNode *curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    trees.emplace_back(curr);
                }
            }
        }
        return trees;
    }

public:
    std::vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        return tree_generator(1, n);
    }
};