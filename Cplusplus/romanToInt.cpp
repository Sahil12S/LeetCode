/*
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int romanToInt( string s );

int main(int argc, char const *argv[])
{
    vector<string> nums = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X" };
    // vector<string> nums = { "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX" };
    // vector<string> nums = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X" };

    // string s = "II";

    for ( string s : nums )
    {
        cout << s << "\t:\t" << romanToInt( s ) << endl;
    }
    return 0;
}

int romanToInt( string s )
{
    unordered_map<char, int> romans;
    romans['I'] = 1;
    romans['V'] = 5;
    romans['X'] = 10;
    romans['L'] = 50;
    romans['C'] = 100;
    romans['D'] = 500;
    romans['M'] = 1000;

    if ( s.length() == 0 )
    {
        return 0;
    }

    int num = romans[ s.back() ];

    for ( int i = s.length() - 2; i >= 0; i-- )
    {
        if( romans[ s[i] ] < romans[ s[i + 1] ] )
        {
            num -= romans[ s[i] ];
        }
        else
        {
            num += romans[ s[i] ];
        }
    }
    return num;
}