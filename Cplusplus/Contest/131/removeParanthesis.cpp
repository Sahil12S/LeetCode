/*
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, 
where A and B are valid parentheses strings, and + represents string concatenation.  
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, a
nd there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: 
S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.
*/

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

string removeOuterParentheses(string S);

int main(int argc, char const *argv[])
{
    string S = "(()())(())";
    cout << removeOuterParentheses( S ) << endl;
    cout << pow( 2, 3) << endl;
    return 0;
}

string removeOuterParentheses( string S )
{
    if ( S.length() <= 2 )
    {
        return "";
    }

    int sIdx = 0;
    int eIdx = 0;

    stack<char> stk;
    // stk.push( S[0] );
    string ans = "";

    for ( int i = 0; i < S.length(); i++ )
    {
        if ( S[i] == '(' )
        {
            if ( stk.empty() )
            {
                sIdx = i;
            }
            stk.push( S[i] );
            continue;
        }
        else
        {
            stk.pop();
            if ( stk.empty() && sIdx < i )
            {
                cout << sIdx << ", " << i << endl;
                cout << S.substr( sIdx + 1, i - sIdx - 1 ) << endl;
                ans += S.substr( sIdx + 1, i - sIdx - 1 );
            } 
        }
    }

    return ans;
}