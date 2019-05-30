/**
 * Given a n-ary tree, find its maximum depth. 
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 */

#include <vector>
#include <queue>

// Definition for a Node.
class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int maxD = 0;
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            ++maxD;
            while (size--)
            {
                Node *node = q.front();
                q.pop();
                for (Node *n : node->children)
                {
                    q.push(n);
                }
            }
        }
        return maxD;
    }
};