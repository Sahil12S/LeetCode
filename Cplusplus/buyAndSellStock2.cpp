// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. 
// You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

#include <iostream>
#include <vector>
// #include <

using namespace std;

int maxProfit( vector<int>& prices );

int main(int argc, char const *argv[])
{
    // vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {1,2,3,4,5};
    vector<int> prices = {7,6,4,3,2,1};
    cout << maxProfit( prices ) << endl;
    
    return 0;
}

int maxProfit( vector<int>& prices )
{
    int maxProfit = 0;
    if ( prices.size() == 0 )
    {
        return maxProfit;
    }

    int i = 0;
    int valley = prices[0];
    int peak = prices[0];

    for ( int i = 0; i < prices.size() - 1; i++ )
    {
        while ( i < prices.size() - 1 && prices[i] >= prices[i + 1] )
        {
            i++;
        }

        valley = prices[i];

        while ( i < prices.size() - 1 && prices[i] < prices[i + 1] )
        {
            i++;
        }


        peak = prices[i];

        maxProfit += peak - valley;
    }
    return maxProfit;
}