#include <vector>

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
private:
    Node *helper(int s_r, int s_c, int len, std::vector<std::vector<int>> &grid)
    {
        Node *node = new Node();
        if (len == 1)
        {
            return new Node(grid[s_r][s_c], true, nullptr, nullptr, nullptr, nullptr);
        }

        int new_len = len / 2;

        Node *topLeft = helper(s_r, s_c, new_len, grid);
        Node *topRight = helper(s_r, s_c + new_len, new_len, grid);
        Node *bottomLeft = helper(s_r + new_len, s_c, new_len, grid);
        Node *bottomRight = helper(s_r + new_len, s_c + new_len, new_len, grid);

        if ((topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) &&
            (topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val))
        {
            bool val = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;

            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node *construct(std::vector<std::vector<int>> &grid)
    {
        return helper(0, 0, grid.size(), grid);
    }
};