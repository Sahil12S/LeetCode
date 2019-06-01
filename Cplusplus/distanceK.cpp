/**
 * We are given a binary tree (with root node root), a target node, and an integer value K.
 * Return a list of the values of all nodes that have a distance K from the target node.
 * he answer can be returned in any order.
 */

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void getParents(TreeNode *node, TreeNode *parent, std::unordered_map<TreeNode *, TreeNode *> &parents)
{
    if (node != nullptr)
    {
        parents[node] = parent;
        getParents(node->left, node, parents);
        getParents(node->right, node, parents);
    }
}

// Returns list of nodes from current
std::vector<int> getNodes(std::queue<TreeNode *> q)
{
    std::vector<int> list;
    int size = q.size();
    while (size--)
    {
        list.emplace_back(q.front()->val);
        q.pop();
    }
    return list;
}

std::vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
{
    std::unordered_map<TreeNode *, TreeNode *> parents;

    getParents(root, nullptr, parents);

    std::queue<TreeNode *> q;
    std::unordered_set<TreeNode *> seen;

    q.push(target);
    seen.insert(target);

    int current_level = 0;

    while (!q.empty())
    {
        // If we are on right level
        if (current_level == K)
        {
            return getNodes(q);
        }

        int size = q.size();

        while (size--)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && !seen.count(curr->left))
            {
                seen.insert(curr->left);
                q.push(curr->left);
            }
            if (curr->right && !seen.count(curr->right))
            {
                seen.insert(curr->right);
                q.push(curr->right);
            }
            if (parents[curr] != nullptr && !seen.count(parents[curr]))
            {
                seen.insert(parents[curr]);
                q.push(parents[curr]);
            }
        }
        current_level++;
    }
    return {};
}