/*
Given an input string , reverse the string word by word. 
Note: 
    A word is defined as a sequence of non-space characters.
    The input string does not contain leading or trailing spaces.
    The words are always separated by a single space.
    Follow up: Could you do it in-place without allocating extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseWords( vector<char>& str );

int main(int argc, char const *argv[])
{
    vector<char> str = { 't','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e' };
    reverseWords( str );

    for ( char c : str )
    {
        cout << c;
    }
    cout << endl;

    return 0;
}

void reverseWords( vector<char>& str )
{
    reverse( str.begin(), str.end() );
    int idx = 0;

    int i = 0;
    while ( i < str.size() )
    {
        idx = i;
        while ( i < str.size() && str[i] != ' ')
        {
            i++;
        }
        reverse( str.begin() + idx, str.begin() + i );
        i++;
    }
    // reverse( str.begin() + idx, str.end() );


}