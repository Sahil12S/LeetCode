// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int coinChange(vector<int>& coins, int amount);
void printVector(vector<int> vec);
#include "../logger.cpp"

int main(int argc, char const *argv[])
{
    vector<int> coins = {2, 5, 10};
    int amount = 12;

    cout << "Min num of coins req for amount " << amount << " is " << coinChange(coins, amount) << endl;
    
    return 0;
}

int coinChange(vector<int>& coins, int amount)
{
    vector<int> reqCoins(amount + 1, amount + 1);
    reqCoins[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        // reqCoins[i] = numeric_limits<int>::max();

        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                reqCoins[i] = min(reqCoins[i - coins[j]] + 1, reqCoins[i]);
            }
        }
    }
    // printVector(reqCoins);

    return reqCoins[amount] > amount ? -1 : reqCoins[amount];

}