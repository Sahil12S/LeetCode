// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit( vector<int>& prices );

int main(int argc, char const *argv[])
{
    // vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    vector<int> prices = { 7, 6, 4, 3, 1 };
    cout << maxProfit( prices ) << endl;
    
    return 0;
}

int maxProfit( vector<int>& prices )
{
    int min_price = numeric_limits<int>::max();
    int max_profit = 0;

    for ( int price : prices )
    {
        int profit = price - min_price;
        if ( profit > max_profit )
        {
            max_profit = profit;
        }
        min_price = min( price, min_price );
    }
    return max_profit;
}