/*
 * Given an encoded string, return it's decoded string.

 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
 * is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

 * You may assume that the input string is always valid; 
 * No extra white spaces, square brackets are well-formed, etc.

 * Furthermore, you may assume that the original data does not contain any digits and 
 * that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/

#include <iostream>
#include <stack>
#include <vector>
#include <assert.h>

std::string decodeString( std::string s );
std::string decodeString2( std::string s );
std::string helper( std::string s, int& idx );

int main(int argc, char const *argv[])
{
    std::vector< std::string > s = { "3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef", "10[leet]" };
    std::vector< std::string > sol = { "aaabcbc", "accaccacc", "abcabccdcdcdef", "leetleetleetleetleetleetleetleetleetleet" };

    for( int i = 0; i < s.size(); i++ )
    {
        std::string ans = decodeString2( s[i] );
        if( sol[i] != ans )
        {
            std::cout << "Wrong answer for: " << s[i] << '\n';
        }
        else
        {
            std::cout << "Ans: " <<  ans << '\n';
        }
        
    }

    return 0;
}

std::string decodeString( std::string s )
{
    std::stack<char> brackets;
    std::stack< std::pair< int, std::string > > numStack;
    std::string ans = "";

    bool isNum = false;

    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '[' || s[i] == ']' )    // Check for brackets
        {
            isNum = false;
            if( s[i] == '[' )   // Opening bracket
            {
                brackets.push( s[i] );
            }
            else
            {
                // Now we pop things out
                std::pair< int, std::string > p = numStack.top();
                numStack.pop();

                // Lets repeat and store it.
                std::string temp = "";
                for( int i = 0; i < p.first; i++ )
                {
                    temp = temp + p.second;
                }

                // Now if our stack is empty, we simply repeat it
                if( !numStack.empty() )
                {
                    numStack.top().second += temp;
                }
                else
                {
                    ans += temp;
                }
            }
        }
        else if( std::isalpha( s[i] ) )     // Check for alphabets
        {
            isNum = false;
            if( !numStack.empty() )
            {
                numStack.top().second += s[i];
            }
            else
            {
                ans += s[i];
            }
            
        }
        else        // It is number otherwise
        {
            if( !isNum )
            {
                numStack.push( std::make_pair( ( s[i] - '0' ), "" ) );
                isNum = true;
            }
            else
            {
                numStack.top().first = numStack.top().first * 10 + ( s[i] - '0' );
            }
            
        }
    }
    return ans;
}

std::string helper( std::string s, int& idx )
{
    std::string res;

    // Keep storing things until first closing bracket is received
    while( idx < s.length() && s[idx] != ']' )
    {
        if( !isdigit( s[idx] ) )
        {
            res += s[idx++];
        }
        else
        {
            // Now we found a digit, create a number out of it
            int n = 0;
            while( idx < s.length() && isdigit( s[idx] ) )
            {
                n = n * 10 + s[idx++] - '0';
            }

            idx++;      // Skip '['
            std::string str = helper( s, idx );
            // Now our idx has reached till ']'
            idx++;      // Skip ']'

            // Now repeat it n times
            while( n-- > 0 )
            {
                res += str;
            }
        }
    }
    return res;

}

std::string decodeString2( std::string s )
{
    int idx = 0;
    return helper( s, idx );
}