/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

bool isSubsequence( string s, string t );

int main(int argc, char const *argv[])
{
    string s = "abc";
    string t = "bahgdc";

    cout << isSubsequence( s, t ) << endl;

    return 0;
}

bool isSubsequence( string s, string t )
{
    unordered_map<char, list<int>> myMap;

    int j = 0;

    for ( int i = 0; i < t.length() && j < s.length(); i++ )
    {
        // myMap[ t[i] ].push_back( i );
        if ( s[j] == t[i] )
        {
            j++;
        }
    }

    return j == s.length();
}