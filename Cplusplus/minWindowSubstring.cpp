
/* 
 * Given a string S and a string T, 
 * find the minimum window in S which will 
 * contain all the characters in T in complexity O(n).
 */

#include "Headers.h"

std::string LeetCode::minWindow( std::string s, std::string t )
{
    if( s.length() == 0 || t.length() == 0 )
    {
        return "";
    }
    std::vector<int> arr(128, 0);

    for( char c : t )
    {
        arr[ c ]++;
    }

    int required = t.length();

    int l = 0;
    int r = 0;

    // Array holding current window size and start, ending index of this window
    std::vector<int> idx = { 0, 0 };


    while( r < s.length() )
    {
        if( arr[s[r]] > 0 )
        {
            required--;
        }
        arr[s[r]]--;
        r++;

        while( required == 0 )
        {
            if( idx[1] == 0 || ( r - l ) < ( idx[1] - idx[0] ) )
            {
                idx[0] = l;
                idx[1] = r;
            }

            arr[s[l]]++;
            
            if( arr[s[l]] > 0 )
            {
                required++;
            }
            l++;
        }
    }

    return s.substr( idx[0], idx[1] - idx[0] );
}