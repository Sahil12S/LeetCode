#include <iostream>
#include <vector>
#include <cmath>

#define MOD_VAL static_cast<int>(std::pow(10, 9) + 7)
using VI = std::vector<int>;
using VVI = std::vector<VI>;

int knightDialer(int N);

int main()
{
    int N = 3;
    std::cout << knightDialer(N) << '\n';
    return 0;
}

int knightDialer(int N)
{
    VVI neighbors = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    VI current(10, 1);

    while (N-- > 1)
    {
        VI next(10, 0);
        for (int i = 0; i < 10; i++)
        {
            for (auto num : neighbors[i])
            {
                next[num] = (next[num] + current[i]) % MOD_VAL;
            }
        }
        current = next;
    }

    long sum = 0;
    for (auto val : current)
    {
        sum += val;
    }

    return static_cast<int>(sum % MOD_VAL);
}