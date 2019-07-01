#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool circularArrayLoop(VI &nums);

int main()
{
    // VI nums = {2, -1, 1, 2, 2}; // True
    // VI nums = {-2, 1, -1, -2, -2}; // False
    // VI nums = {-1, -2, -3, -4, -5}; // False
    // VI nums = {1, -2}; // False
    // VI nums = {2, -1, 2, -1, 3}; // True
    // VI nums = {-1, -2, -3, -4, -5}; // False
    VI nums = {-1, -1, -1}; // True
    std::cout << circularArrayLoop(nums) << '\n';
    return 0;
}

bool circularArrayLoop(VI &nums)
{
    int n = nums.size();
    std::vector<bool> visited(n, false);

    FORI(0, n)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;

        int idx = i;

        std::unordered_set<int> s;

        while (true)
        {
            int next = ((nums[idx] + idx) % n + n) % n;

            if (next == idx || nums[idx] * nums[next] < 0)
            {
                break;
            }
            if (s.count(next))
            {
                return true;
            }
            s.insert(idx);
            idx = next;
            visited[next] = true;
        }
    }
    return false;
}
