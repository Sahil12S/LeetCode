// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit( vector<int>& prices );

int main(int argc, char const *argv[])
{
    // vector<int> prices = {3,3,5,0,0,3,1,4};
    // cout << maxProfit( prices ) << " -> 6" << endl;

    vector<int> prices = {1,2,3,4,5};
    cout << maxProfit( prices ) << " -> 4" << endl;
    
    return 0;
}

int maxProfit( vector<int>& prices )
{
    // First we find profits on first transaction
    vector<int> profits_on_first_transaction( prices.size(), 0 );

    int max_profit = 0;
    int min_price = numeric_limits<int>::max();

    for ( int i = 0; i < prices.size(); i++ )
    {
        int profit = prices[i] - min_price;

        if ( profit > max_profit )
        {
            max_profit = profit;
        }
        profits_on_first_transaction[i] = max_profit;
        min_price = min ( prices[i], min_price );
    }

    // Now we look for second transaction
    int max_price = numeric_limits<int>::min();

    for ( int i = prices.size() - 1; i > 0; i-- )
    {
        max_price = max( max_price, prices[i] );
        int curr__profit = max_price - prices[i];
        max_profit = max( curr__profit + profits_on_first_transaction[i - 1], max_profit );
    }
    return max_profit;
}