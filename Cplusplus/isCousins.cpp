/**
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
 * Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
 * We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
 * Return true if and only if the nodes corresponding to the values x and y are cousins.
 */

#include <vector>
#include <queue>

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
/*      RECURSION
class Solution
{
    TreeNode *helper(TreeNode *node, int val, int curr_height, int &height)
    {
        if (!node)
        {
            return nullptr;
        }

        if ((node->left && node->left->val == val) || (node->right && node->right->val == val))
        {
            height = curr_height;
            // cout << height << endl;
            return node;
        }

        TreeNode *left = helper(node->left, val, curr_height + 1, height);
        if (left)
            return left;

        TreeNode *right = helper(node->right, val, curr_height + 1, height);
        if (right)
            return right;

        return nullptr;
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        int x_d = 0;
        int y_d = 0;
        TreeNode *first = helper(root, x, 1, x_d);
        TreeNode *second = helper(root, y, 1, y_d);

        // cout << x_d << "  " << y_d << '\n';

        return (x_d == y_d && first != second);
    }
};
*/

///* BFS
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->val == x || root->val == y)
        {
            return false;
        }

        std::vector<TreeNode *> parents;

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty() && parents.size() != 2)
        {
            int width = q.size();
            while (width && parents.size() != 2)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                {
                    if (curr->left->val == x || curr->left->val == y)
                    {
                        parents.emplace_back(curr);
                    }
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    if (curr->right->val == x || curr->right->val == y)
                    {
                        parents.emplace_back(curr);
                    }
                    q.push(curr->right);
                }

                width--;
            }

            // If we only found one value on current level
            if (parents.size() == 1)
            {
                return false;
            }
        }

        return parents[0] != parents[1];
    }
};
//*/