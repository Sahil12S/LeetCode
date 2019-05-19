/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 */

#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>

std::string convert( std::string s, int numRows );

int main(int argc, char const *argv[])
{
    std::string s = "PAYPALISHIRING";
    int numRows = 4;
    std::cout << convert( s, numRows ) << '\n';
    std::cout << convert( s, 3 ) << '\n';
    return 0;
}

std::string convert( std::string s, int numRows )
{
    if( numRows == 1 )
    {
        return s;
    }

    int rows = std::min( static_cast<int>( s.size() ), numRows );

    std::vector<std::string> vec( rows );

    bool goingDown = false;
    int currRow = 0;

    for( char c : s )
    {
        // Add character to current row
        vec[currRow] += c;

        // See if we have to change direction
        if( currRow == 0 || currRow == rows - 1 )
        {
            goingDown = !goingDown;
        }

        currRow += goingDown ? 1 : -1;
    }

    std::string ans;

    // Concat everything now
    for( std::string val : vec )
    {
        ans += val;
    }

    return ans;
}