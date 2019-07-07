/**
 * Given a binary tree, return the vertical order traversal of its nodes' values.
 * (ie, from top to bottom, column by column).
 * If two nodes are in the same row and column,
 * the order should be from left to right.
 */

#include <vector>
#include <queue>
#include <map>

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
    std::vector<std::vector<int>> verticalOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        // Stores the column number and list of values that lie on that column.
        std::map<int, std::vector<int>> m;

        // Store TreeNode with their column number
        std::queue<std::pair<TreeNode *, int>> q;

        // Keep track of minimum and maximum value of column number
        int min_col = 0;
        int max_col = 0;

        q.push({root, 0});

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int col = q.front().second;
            q.pop();

            m[col].push_back(node->val);

            if (node->left)
            {
                q.push({node->left, col - 1});
                min_col = std::min(min_col, col - 1);
            }
            if (node->right)
            {
                q.push({node->right, col + 1});
                max_col = std::max(max_col, col + 1);
            }
        }

        std::vector<std::vector<int>> result;

        // Now travel from min column and add it to result
        for (int i = min_col; i <= max_col; i++)
        {
            result.push_back(m[i]);
        }
        return result;
    }
};