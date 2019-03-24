/*
    Given an array nums, there is a sliding window of size k which is moving from the very
    left of the array to the very right. You can only see the k numbers in the window.
    Each time the sliding window moves right by one position. Return the max sliding window.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
/* Version 1
vector<int> maxSlidingWindow( vector<int>& nums, int k );
int findMax( vector<int>& nums, int i, int j );
*/
vector<int> maxSlidingWindow( vector<int>& nums, int k );

void printVector( vector<int> vec );
#include "logger.cpp"

int main(int argc, char const *argv[])
{
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // vector<int> nums = {9, 11};
    // vector<int> nums = {7, 2, 4};
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    printVector( maxSlidingWindow( nums, k ) );

    return 0;
}

/* Version 2
*/

vector<int> maxSlidingWindow( vector<int>& nums, int k )
{
    if ( k <= 1 || nums.size() <= 1 )
    {
        return nums;
    }

    vector<int> ans;
    deque<int> dq;
    // dq.push_back ( nums[0] );

    

    // ans.emplace_back( nums[dq.front()] );

    for ( int i = 0; i < nums.size(); i++ )
    {
        // cout << dq.size() << endl;
        if ( !dq.empty() && dq.front() == i - k )
        {
            dq.pop_front();
        }
        while ( !dq.empty() && nums[i] > nums[dq.back()] )
        {
            dq.pop_back();
        }
        dq.push_back( nums[i] );

        if ( i >= k - 1 )
        {
            ans.emplace_back( nums[dq.front()] );
        }
    }
    return ans;
}


/* Version 1
vector<int> maxSlidingWindow( vector<int>& nums, int k )
{
    if ( k <= 1 )
    {
        return nums;
    }
    vector<int> ans;
    // int maxN = ;
    
    ans.emplace_back( findMax( nums, 0, k-1 ) );

    for ( int i = k; i < nums.size(); i++ )
    {
        // ans.emplace_back( max )
        // maxN = ;
        ans.emplace_back( findMax( nums, i - k + 1 , i ) );
    }
    return ans;
}

int findMax( vector<int>& nums, int i, int j )
{
    int maxN = nums[i];
    // cout << i << ", " << j << endl;
    for ( int k = i; k <= j; k++ )
    {
        if ( nums[k] > maxN )
        {
            maxN = nums[k];
        }
    }
    return maxN;
}
*/