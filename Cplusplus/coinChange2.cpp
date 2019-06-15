/**
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that amount.
 * You may assume that you have infinite number of each kind of coin.
 */

#include <vector>
#include <iostream>

int change(int amount, std::vector<int> &coins);

int main()
{
    int amount = 5;
    std::vector<int> coins = {1, 2, 5};
    std::cout << change(amount, coins) << '\n';
    return 0;
}

int change(int amount, std::vector<int> &coins)
{
    int N = coins.size();

    std::vector<int> counts(amount + 1, 0);
    counts[0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            counts[j] += counts[j - coins[i]];
        }
    }
    return counts[amount];
}