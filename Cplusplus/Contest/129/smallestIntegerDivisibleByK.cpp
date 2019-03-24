// Given a positive integer K, you need find the smallest positive integer N 
// such that N is divisible by K, and N only contains the digit 1.
// Return the length of N.  If there is no such N, return -1.

#include <iostream>
#include <limits>

using namespace std;

int smallestRepunitDivByK( int K );

int main(int argc, char const *argv[])
{
    // int K = 1;      // 1
    // int K = 2;      // -1
    int K = 3;      // 3

    cout << smallestRepunitDivByK( K ) << endl;

    return 0;
}

int smallestRepunitDivByK( int K )
{
    int value = 0;
    int length = 0;

    if ( K % 2 == 0 )
    {
        return -1;
    }

    for ( int i = 0; i < 1e6; i++ )
    {
        value = (value * 10 + 1) % K;
        length++;

        if ( value == 0 )
        {
            return length;
        }
    }
    return -1;
}