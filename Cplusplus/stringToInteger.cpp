// Implement atoi which converts a string to an integer.

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int myAtoi( string str );

int main(int argc, char const *argv[])
{
    // string s = "words and 987";
    string s = "4193 with words";
    cout << myAtoi( s ) << endl;
    return 0;
}

int myAtoi( string str )
{
    int ans = 0;
    bool started = false;
    int isNegative = 1;    

    for ( char c : str )
    {
        if ( c == ' ' && !started )
        {
            continue;
        }

        if ( c == '+' && !started )
        {
            started = true;
            continue;
        }
        if ( c == '-' && !started )
        {
            started = true;
            isNegative = -1;
            continue;
        }

        cout << c - '0' << endl;
        if ( c - '0' >= 0 && c - '0' <= 9 )
        {
            if ( !started )
            {
                started = true;
            }

            int n = (c - '0') * isNegative;
            if ( isNegative > 0 && ans > ( INT32_MAX - n ) / 10 )
            {
                return INT32_MAX;
            }
            else if ( isNegative < 0 && ans < ( INT32_MIN - n ) / 10 )
            {
                return INT32_MIN;
            }
            else
            {
                ans = ans * 10 + n;
                cout << "ans: " << ans << endl;
            }
            continue;
            // return ans * isNegative;
        }
        cout << "broke" << endl;
        break;        
    }
    return ans;
}