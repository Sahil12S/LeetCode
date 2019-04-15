/*
    Given an unsorted array of integers, find the length of longest increasing subsequence.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Brute force approach
int lengthOfLIS( vector<int>& nums );
int helper( vector<int>& nums, int prevVal, int currPos );

// Dynamic Programming approach
int lengthOfLIS2( vector<int>& nums );

// DP and Binary Search
int lengthOfLIS3( vector<int>& nums );

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS3( nums ) << endl;
    return 0;
}

int lengthOfLIS( vector<int>& nums )
{
    return helper( nums, numeric_limits<int>::min(), 0 );
}

int helper( vector<int>& nums, int prevVal, int currPos )
{
    if ( currPos == nums.size() )
    {
        return 0;
    }

    int taken = 0;

    if ( nums[currPos] > prevVal )
    {
        taken = 1 + helper( nums, nums[currPos], currPos + 1 );
    }

    int notTaken = helper( nums, prevVal, currPos + 1 );

    return max( taken, notTaken );
}

int lengthOfLIS2( vector<int>& nums )
{
    if ( nums.size() == 0 )
    {
        return 0;
    }

    vector<int> dp( nums.size() );
    dp[0] = 1;
    int maxAns = 1;

    for ( int i = 1; i < dp.size(); i++ )
    {
        int maxVal = 0;
        for ( int j = 0; j < i; j++ )
        {
            if ( nums[i] > nums[j] )
            {
                maxVal = max( dp[j], maxVal );
            }
        }

        dp[i] = maxVal + 1;
        maxAns = max( maxAns, dp[i] );
    }
    return maxAns;
}

int lengthOfLIS3( vector<int>& nums )
{
    vector<int> dp;
    vector<int>::iterator it;

    for ( int n : nums )
    {
        it = lower_bound( dp.begin(), dp.end(), n );
        if ( it != dp.end() )
        {
            *it = n;
        }
        else
        {
            dp.emplace_back( n );
        }
    }
    return dp.size();
}