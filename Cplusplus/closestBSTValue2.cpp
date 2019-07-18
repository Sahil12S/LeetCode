/**
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 * 
 * Note:
 * 
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 */

#include <vector>
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
    std::vector<int> tree_values;
    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        tree_values.push_back(node->val);
        inorder(node->right);
    }

public:
    std::vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        if (!root || k == 0)
        {
            return {};
        }

        // Get inorder values from tree
        inorder(root);
        int n = tree_values.size();

        // We find position of index where our target would be inserted in our array
        // lower_bound uses Binary search
        auto it = lower_bound(tree_values.begin(), tree_values.end(), target);
        int idx = std::min(static_cast<int>(it - tree_values.begin()), n - 1);

        // Find if it's closest to our target or the previous value is
        if (idx > 0 && tree_values[idx] - target > target - tree_values[idx - 1])
        {
            idx--;
        }

        std::vector<int> ans(k);
        ans[0] = tree_values[idx];

        // Get left and right indices from current position
        int left = idx - 1;
        int right = idx + 1;

        // Travel in direction where difference is minimum
        // until we have saved k values
        for (int i = 1; i < k; i++)
        {
            if (left >= 0 && right < n && target - tree_values[left] < tree_values[right] - target)
            {
                ans[i] = tree_values[left];
                left--;
            }
            else if (left >= 0 && right < n && target - tree_values[left] >= tree_values[right] - target)
            {
                ans[i] = tree_values[right];
                right++;
            }
            else
            {
                // Check if we have reach one end our array
                if (left < 0)
                {
                    ans[i] = tree_values[right];
                    right++;
                }
                else
                {
                    ans[i] = tree_values[left];
                    left--;
                }
            }
        }

        return ans;
    }
};