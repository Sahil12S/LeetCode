/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */

#include <iostream>
#include <vector>

int numDecodeWays( std::string s );
// int helper( std::string s, int idx );

int main(int argc, char const *argv[])
{
    std::string s = "12";

    std::cout << numDecodeWays( s ) << '\n';

    return 0;
}

int numDecodeWays( std::string s )
{
    /*
    int n = s.size();
    std::vector<int> dp( n + 1, 0 );
    dp[n] = 1;

    for( int i = n - 1; i >= 0; --i )
    {
        if( s[i] == '0' )
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            
            if( i < n - 1 && ( s[i] == '1' || ( s[i] == '2' && s[i + 1] < '7' ) ) )
            {
                dp[i] += dp[i + 2];
            }
        }
    }
    */

   int count = 1;
   int prevCount;
   int n = s.size();

   for( int i = n - 1; i >= 0; i-- )
   {
       int curr = s[i] == '0' ? 0 : count;
       if( i < n - 1 && ( s[i] == '1' || ( s[i] == '2' && s[i + 1] < '7' ) ) )
       {
           curr += prevCount;
       }
       prevCount = count;
       count = curr;
   }

    return s.empty() ? 0 : count;
}

/* RECURSION
int numDecodeWays( std::string s )
{
    return s.empty() ? 0 : helper( s, 0 );
}

int helper( std::string s, int idx )
{
    if( idx == s.length() )
    {
        return 1;
    }
    if( s[idx] == '0' )
    {
        return 0;
    }

    int res = helper( s, idx + 1 );

    if( idx < s.length()-1 && ( s[idx] == '1' || ( s[idx] == '2' && s[idx + 1] < '7' ) ) )
    {
        res += helper( s, idx + 2 );
    }

    return res;
}
*/