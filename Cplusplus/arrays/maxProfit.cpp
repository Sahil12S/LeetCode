#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
    // vector<int> nums = {1, 2, 3, 4, 5};
    // vector<int> nums = {7, 1, 5, 3, 6, 4};
    // vector<int> nums = {7, 6, 4, 3, 1};
    vector<int> nums = {2, 1, 2, 0, 1};
    int profit = maxProfit(nums);

    printf("Profit: %d\n", profit);

    // for (size_t i = 0; i < nums.size(); i++) {
    //     printf("%d", nums[i]);
    // }
    // printf("\n");

    return 0;
}

int maxProfit(vector<int>& prices) {
    int total_profit = 0, profit = 0;

    int buyingOn = 0;
    int sellingOn = buyingOn + 1;


    while (sellingOn < prices.size()) {
        printf("Buying price: %d\n", prices[buyingOn]);
        printf("Selling price: %d\n", prices[sellingOn]);
        if ( prices[buyingOn] > prices[sellingOn] && profit == 0) {
            ++buyingOn;
            ++sellingOn;
        } else if (profit < (prices[sellingOn] - prices[buyingOn])) {
            profit = prices[sellingOn] - prices[buyingOn];
            printf("Interim Profit: %d\n", profit);
            ++sellingOn;
            // total_profit += profit;
        } else {
            buyingOn = sellingOn;
            ++sellingOn;
            total_profit += profit;
            profit = 0;
        }
    }
    total_profit += profit;
    return total_profit;
}
