/* 
 * Q 41
 * Given an unsorted integer array, find the smallest missing positive integer.
 */

#include <iostream>
#include <vector>

int firstMissingPositive( std::vector<int>& nums );

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {3,4,-1,1};
    std::cout << firstMissingPositive( nums ) << '\n';
    
    return 0;
}

int firstMissingPositive( std::vector<int>& nums )
{
    int len = nums.size();
    bool hasOne = false;

    for( int i : nums )
    {
        if( i == 1 )
        {
            hasOne = true;
            break;
        }
    }

    // If 1 is missing then 1's the answer
    if( !hasOne )
    {
        return 1;
    }

    // If size is one, then 2's the answer
    if( len == 1 )
    {
        return 2;
    }

    // Let's convert, all numbers less than or equal to zero 
    // And all numbers greater than len to 1
    // Since missing number will either be between 1 - len or len + 1
    for( int i = 0; i < len; i++ )
    {
        if( nums[i] <= 0 || nums[i] > len )
        {
            nums[i] = 1;
        }
    }

    for( int i = 0; i < len; i++ )
    {
        int a = abs( nums[i] );

        if( a == len )
        {
            nums[0] = -abs( nums[0] );
        }
        else
        {
            nums[a] = -abs( nums[a] );
        }
    }

    for( int i = 1; i < len; i++ )
    {
        if( nums[i] > 0 )
        {
            return i;
        }
    }

    if( nums[0] > 0 )
    {
        return len;
    }

    // All elements are present, so return +1
    return len + 1;
}