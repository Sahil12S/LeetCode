/**
 * Given a binary tree, return the vertical order traversal of its nodes values.
 * For each node at position (X, Y),
 * its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
 * Running a vertical line from X = -infinity to X = +infinity,
 * whenever the vertical line touches some nodes,
 * we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
 * If two nodes have the same position,
 * then the value of the node that is reported first is the value that is smaller.
 * Return an list of non-empty reports in order of X coordinate.
 * Every report will have a list of values of nodes.
 */

#include <map>
#include <set>
#include <vector>

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
    std::map<int, std::map<int, std::multiset<int>>> m;
    void dfs(int x, int y, TreeNode *node)
    {
        if (node != nullptr)
        {
            m[x][y].insert(node->val);
            dfs(x - 1, y + 1, node->left);
            dfs(x + 1, y + 1, node->right);
        }
    }

public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode *root)
    {

        dfs(0, 0, root);

        std::vector<std::vector<int>> result;
        for (auto it1 = m.begin(); it1 != m.end(); it1++)
        {
            result.push_back(std::vector<int>());
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
            {
                result.back().insert(end(result.back()), begin(it2->second), end(it2->second));
            }
        }
        return result;
    }
};