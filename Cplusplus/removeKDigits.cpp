// Given a non-negative integer num represented as a string,
// remove k digits from the number so that the new number is the smallest possible.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string removeKdigits( string num, int k );

int main(int argc, char const *argv[])
{
    string num = "1432219";
    int k = 3;
    // string num = "10200";
    // int k = 1;
    // string num = "9";
    // int k = 1;
    // string num = "10";
    // int k = 2;
    // string num = "112";
    // int k = 1;

    cout << removeKdigits( num, k ) << endl;

    return 0;
}


string removeKdigits( string num, int k )
{
    if ( k >= num.size() )
    {
        return "0";
    }

    vector<char> s;

    string ans;

    num += '0';

    for ( int i = 0; i < num.length(); i++ )
    {
        while ( !s.empty() && s.back() > num[i] && k > 0 )
        {
            s.pop_back();
            k--;
        }
        s.push_back( num[i] );
    }

    for ( int i = 0; i < s.size() - 1; i++ )
    {
        if ( ans.length() == 0 && s[i] == '0' )
        {
            continue;
        }
        ans += s[i];
    }
    return ans.length() == 0 ? "0" : ans;
}