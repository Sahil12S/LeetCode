// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

int main()
{
    // vector<int> candies = { 2, 3, 5, 1, 3 };
    // int extraCandies = 3;
    // vector<int> candies = { 4, 2, 1, 1, 2 };
    // int extraCandies = 1;
    vector<int> candies = { 12, 1, 12 };
    int extraCandies = 10;
    vector<bool> res = kidsWithCandies(candies, extraCandies);

    for (bool out : res)
    {
        cout << out << ' ';
    }
    cout << '\n';

    return 0;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int curr_max = 0;

    for (int count : candies)
    {
        if (count > curr_max)
        {
            curr_max = count;
        }
    }
    vector<bool> res(candies.size(), false);
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= curr_max)
        {
            res[i] = true;
        }
    }
    return res;
}