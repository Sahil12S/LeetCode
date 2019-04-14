/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> majorityElement( vector<int>& nums );

int main(int argc, char const *argv[])
{
    // vector<int> nums = {3, 2, 3};
    vector<int> nums = {1,2,2,1,3,3,1,3};
    vector<int> ans = majorityElement( nums );

    for ( auto n : ans )
    {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}

// for n/3 there can be atmost 2 elements with more occurance

vector<int> majorityElement( vector<int>& nums )
{
    if ( nums.size() == 0 )
    {
        return {};
    }

    vector<int> result;

    int candidate1 = numeric_limits<int>::max();
    int candidate2 = numeric_limits<int>::max();
    int count1 = 0;
    int count2 = 0;

    for ( auto n : nums )
    {
        if ( candidate1 == n )
        {
            count1++;
        }
        else if ( candidate2 == n )
        {
            count2++;
        }
        else if ( count1 == 0 )
        {
            candidate1 = n;
            count1 = 1;
        }
        else if ( count2 == 0 )
        {
            candidate2 = n;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;

    for ( auto n : nums )
    {
        if ( n == candidate1 )
        {
            count1++;
        }
        else if ( n == candidate2 )
        {
            count2++;
        }
    }

    if ( count1 > nums.size()/3 )
    {
        result.emplace_back( candidate1 );
    }
    if ( count2 > nums.size()/3 )
    {
        result.emplace_back( candidate2 );
    }

    return result;
}