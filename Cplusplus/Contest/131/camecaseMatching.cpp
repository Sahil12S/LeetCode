/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. 
(We may insert each character at any position, and may insert 0 characters.)
Given a list of queries, and a pattern, return an answer list of booleans, 
where answer[i] is true if and only if queries[i] matches the pattern.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> camelMatch(vector<string>& queries, string pattern);
bool checkPattern( const string& query, const string& pattern );

int main(int argc, char const *argv[])
{
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FoBaT";
    vector<bool> ans = camelMatch( queries, pattern );

    for ( auto a : ans )
    {
        cout << a << endl;
    }

    return 0;
}

vector<bool> camelMatch(vector<string>& queries, string pattern)
{
    vector<bool> result;
    for ( string q : queries )
    {
        result.emplace_back( checkPattern( q, pattern ) );
    }
    return result;
}

bool checkPattern( const string& query, const string& pattern )
{
    int pIdx = 0;

    for ( char c : query )
    {
        if ( pIdx < pattern.length() && pattern[pIdx] == c )
        {
            pIdx++;
        } else if ( isupper( c ) )
        {
            return false;
        }
    }
    return pIdx == pattern.length();
}