/**
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children.The binary tree has the following definition :
 *
 * struct Node
 * {
 *      int val;
 *      Node *left;
 *      Node *right;
 *      Node *next;
 * }
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 */

#include <iostream>
#include <queue>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// Using extra space (using queue)
// Not a correct method when you just want to point to immediate right node
Node *connect1(Node *root)
{
    if (root == nullptr)
    {
        return root;
    }

    std::queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (!curr)
        {
            if (q.size() > 0)
            {
                q.push(nullptr);
            }
        }
        else
        {
            curr->next = q.front();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return root;
}

// Using recursion and no extra space other than intermediate recursive stack
Node *connect2(Node *root)
{
    if (!root)
    {
        return root;
    }

    if (root->left != nullptr)
    {
        root->left->next = root->right;
    }
    if (root->right != nullptr && root->next != nullptr)
    {
        root->right->next = root->next->left;
    }

    connect2(root->left);
    connect2(root->right);
    return root;
}

Node *connect3(Node *root)
{
    Node *start_node = root;

    while (start_node)
    {
        Node *curr = start_node;

        while (curr)
        {
            if (curr->left)
            {
                curr->left->next = curr->right;
            }

            if (curr->right && curr->next)
            {
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
        start_node = start_node->left;
    }
    return root;
}