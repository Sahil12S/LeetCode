/**
 * Given an array of non-negative integers,
 * you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 */

#include <iostream>
#include <vector>

#define FORI(s, n) for (int i = s; i >= n; i--)
#define FORJ(s, n) for (int j = s; j <= n; j++)

using VB = std::vector<bool>;
using VI = std::vector<int>;

bool canJump(VI &nums);

int main()
{
    // VI nums = {2, 3, 1, 0, 4};
    VI nums = {3, 2, 1, 0, 4};
    std::cout << canJump(nums) << std::endl;
    return 0;
}

/**
 * 0 is bad index, i.e., we can't reach end
 * 1 is good index, i.e., we can reach end
 */

bool canJump(VI &nums)
{
    /**
    VI mem(nums.size(), 0);
    mem[nums.size() - 1] = 1;

    FORI(nums.size() - 1, 0)
    {
        int max_jump_len = std::min(i + nums[i], static_cast<int>(nums.size() - 1));

        FORJ(i + 1, max_jump_len)
        {
            if (mem[j])
            {
                mem[i] = 1;
                break;
            }
        }
    }

    return mem[0];
*/

    // Just keep track of last position from where
    // we can reach end.
    // if from current position, we can reach that position
    // or beyond that, it means we can reach end from current
    // position and now we keep track of this position

    int last_pos = nums.size() - 1;

    FORI(nums.size() - 1, 0)
    {
        if (i + nums[i] >= last_pos)
        {
            last_pos = i;
        }
    }
    return last_pos == 0;
}