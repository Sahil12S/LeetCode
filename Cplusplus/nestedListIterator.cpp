#include <vector>
#include <queue>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator
{
private:
    // queue<queue<int>> q;
    std::queue<int> q;

    void helper(std::vector<NestedInteger> nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                // cout << "push: " << nestedList[i].getInteger() << endl;
                q.push(nestedList[i].getInteger());
            }
            else
            {
                helper(nestedList[i].getList());
            }
        }
    }

public:
    NestedIterator(std::vector<NestedInteger> &nestedList)
    {
        helper(nestedList);
        // cout << q.size() << endl;
    }

    int next()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    bool hasNext()
    {
        return q.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */