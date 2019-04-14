// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining.

#include <iostream>
#include <vector>

using namespace std;

int trap( vector<int>& height );
int trap2( vector<int>& height );

int main(int argc, char const *argv[])
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap2( height ) << endl;
    return 0;
}


int trap( vector<int>& height )
{
    int size = height.size();
    if ( size == 0 )
    {
        return 0;
    }
    vector<int> maxL( size ), maxR( size );

    int ans = 0;

    maxL[0] = height[0];
    for ( int i = 1; i < size; i++ )
    {
        maxL[i] = max( height[i], maxL[i - 1] );
    }

    maxR[size - 1] = height[size - 1];
    for ( int i = size - 2; i >= 0; i-- )
    {
        maxR[i] = max( height[i], maxR[i + 1] );
    }

    for ( int i = 1; i < size - 1; i++ )
    {
        ans += min( maxL[i], maxR[i] ) - height[i];
    }

    return ans;
}

int trap2( vector<int>& height )
{
    int size = height.size();
    if ( size == 0 )
    {
        return 0;
    }

    int left = 0, right = size - 1;
    int result = 0;
    int maxL = 0, maxR = 0;

    while ( left < right )
    {
        if ( height[left] < height[right] )
        {
            if ( height[left] >= maxL )
            {
                maxL = height[left];
            }
            else
            {
                result += maxL - height[left];
            }
            left++;
        }
        else
        {
            if ( height[right] >= maxR )
            {
                maxR = height[right];
            }
            else
            {
                result += maxR - height[right];
            }
            right--;
        }
    }
    return result;
}