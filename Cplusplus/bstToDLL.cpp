/**
 * Convert a BST to a sorted circular doubly-linked list in-place.
 */

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
private:
    Node *first = nullptr;
    Node *last = nullptr;

    void helper(Node *node)
    {
        if (node)
        {
            // Travel to the left most node
            helper(node->left);

            if (last)
            {
                // If last is set, update right pointer of it
                // as pointing to current node &
                // current node's left pointer to last node
                last->right = node;
                node->left = last;
            }
            else
            {
                // If last node is not yet set
                // it means, first is not set too.
                // Set first as current node
                first = node;
            }
            // Update last node as current node
            last = node;
            // Go to right subtree
            helper(node->right);
        }
    }

public:
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
        {
            return root;
        }

        helper(root);

        last->right = first;
        first->left = last;
        return first;
    }
};