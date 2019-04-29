// Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
// There is no limit on how many times a digit can be reused.
// You may assume the given input string is always valid.
// For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

#include <iostream>
#include <set>

using namespace std;

string nextClosestTime( string time );

int main(int argc, char const *argv[])
{
    // string time = "19:34";
    string time = "23:59";
    cout << nextClosestTime( time ) << endl;
    return 0;
}

string nextClosestTime( string time )
{
    set<int> s;
    s.insert( time[0] - '0' );
    s.insert( time[1] - '0' );
    s.insert( time[3] - '0' );
    s.insert( time[4] - '0' );

    size_t pos = time.find(':');
    int curr_time = stoi( time.substr( 0, pos ) ) * 60 + stoi( time.substr( pos + 1 ) );

    while ( curr_time < 1440 )
    {
        curr_time += 1;
        if ( curr_time == 1440 )
        {
            curr_time = 0;
        }

        if ( s.count( curr_time / 60 / 10 ) == 0 ||
            s.count( curr_time / 60 % 10 ) == 0 ||
            s.count( curr_time % 60 / 10 ) == 0 ||
            s.count( curr_time % 60 % 10 ) == 0 )
        {
            continue;
        }
        else
        {
            break;
        }
    }

    string res;
    if ( curr_time / 60 < 10 )
    {
        res = "0" + res;
    }
    res += to_string( curr_time / 60 ) + ":";
    if ( curr_time % 60 < 10 )
    {
        res += "0";
    }
    res += to_string( curr_time % 60 );

    return  res;
}