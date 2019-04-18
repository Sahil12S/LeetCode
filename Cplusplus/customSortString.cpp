/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
S was sorted in some custom order previously. 
We want to permute the characters of T so that they match the order that S was sorted.
More specifically, if x occurs before y in S, then x should occur before y in the returned string.
Return any permutation of T (as a string) that satisfies this property.
*/

#include <iostream>
#include <vector>

using namespace std;

string customSortString( string S, string T );

int main(int argc, char const *argv[])
{
    string S = "cba";
    string T = "abcd";

    cout << customSortString( S, T ) << endl;
    return 0;
}


string customSortString( string S, string T )
{
    vector<int> letters( 26 );
    
    for ( char c : T )
    {
        letters[c - 'a']++;
    }
    
    int t_idx = 0;
    
    for ( int i = 0; i < S.length(); i++ )
    {
        while ( letters[ S[i] - 'a' ] > 0 && t_idx < T.length() )
        {
            T[t_idx] = S[i];
            letters[ T[t_idx] - 'a' ]--;
            t_idx++;
        }
    }

    for ( int i = 0; i < 26; i++ )
    {
        while ( letters[i] > 0 )
        {
            T[t_idx++] = i + 'a';
            letters[i]--;
        }
    }
    return T;
}