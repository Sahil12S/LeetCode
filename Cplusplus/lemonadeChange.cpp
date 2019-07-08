/**
 * At a lemonade stand, each lemonade costs $5. 
 * 
 * Customers are standing in a queue to buy from you,
 * and order one at a time (in the order specified by bills).
 * 
 * Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
 * You must provide the correct change to each customer,
 * so that the net transaction is that the customer pays $5.
 *
 * Note that you don't have any change in hand at first.
 *
 * Return true if and only if you can provide every customer with correct change.
 */

#include <iostream>
#include <vector>
#include <map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j > n; j--)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool lemonadeChange(VI &bills);

int main()
{
    // VI bills = {5, 5, 5, 10, 20};
    // VI bills = {5, 5, 10};
    // VI bills = {10, 10};
    VI bills = {5, 5, 10, 10, 20};
    std::cout << lemonadeChange(bills) << '\n';
    return 0;
}

bool lemonadeChange(VI &bills)
{
    int five = 0;
    int ten = 0;

    for (auto bill : bills)
    {
        if (bill == 5)
        {
            five++;
        }
        else if (bill == 10)
        {
            five--;
            ten++;
        }
        else if (ten > 0)
        {
            ten--;
            five--;
        }
        else
        {
            five -= 3;
        }

        if (five < 0)
        {
            return false;
        }
    }
    return true;
}