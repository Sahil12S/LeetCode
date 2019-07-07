/**
 * We have a collection of rocks, each rock has a positive integer weight.
 * 
 * Each turn, we choose the two heaviest rocks and smash them together.
 * Suppose the stones have weights x and y with x <= y.  The result of this smash is:
 * 
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 */

#include <iostream>
#include <vector>
#include <queue>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;

int lastStoneWeight(VI &stones);

int main()
{
    VI stones = {2, 7, 4, 1, 8, 1};
    std::cout << lastStoneWeight(stones) << '\n';
    return 0;
}

int lastStoneWeight(VI &stones)
{
    std::priority_queue<int> pq;
    for (auto stone : stones)
    {
        pq.push(stone);
    }

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        // if (y > x)
        // {
        pq.push(y - x);
        // }
    }

    std::cout << pq.top() << '\n';
    return pq.empty() ? 0 : pq.top();
}