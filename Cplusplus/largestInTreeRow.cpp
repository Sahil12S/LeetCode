// You need to find the largest value in each row of a binary tree.

#include <vector>
#include <queue>
#include <limits>

using namespace std;

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

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> retval;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int max_num = numeric_limits<int>::min();

            while (size)
            {
                TreeNode *curr = q.front();
                q.pop();
                max_num = max(curr->val, max_num);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }

                size--;
            }
            retval.emplace_back(max_num);
        }
        return retval;
    }
};