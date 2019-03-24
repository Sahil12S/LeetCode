/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N,
return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.
*/

#include <iostream>
#include <string>

using namespace std;

bool queryString( string S, int N );
string convertToBinary( int N );

int main(int argc, char const *argv[])
{
    // string S = "0110";
    // int N = 4;

    string S = "110101011011000011011111000000";
    int N = 15;

    cout << queryString( S, N ) << endl;

    return 0;
}

bool queryString( string S, int N )
{
    for( int i = 0; i <= N; i++ )
    {
        if ( S.find( convertToBinary( i ) ) == string::npos )
        {
            return false;
        }

    }
    return true;
}

string convertToBinary( int N )
{
    string s;
    while ( N > 0 )
    {
        s = to_string( N % 2 ) + s;
        N /= 2;
    }
    cout << s << endl;
    return s;
}