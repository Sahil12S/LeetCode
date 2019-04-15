/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Brute force
int numMatchingSubseq( string S, vector<string>& words );


int numMatchingSubseq2( string S, vector<string>& words );

int main(int argc, char const *argv[])
{
    string S = "abcde";
    vector<string> words = { "a", "bb", "acd", "ace" };

    cout << numMatchingSubseq2( S, words ) << endl;

    return 0;
}

int numMatchingSubseq( string S, vector<string>& words )
{
    int count = 0;

    for ( string word : words )
    {
        size_t it = 0;
        for ( char c : word )
        {
            it = S.find( c, it );
            if ( it != string::npos )
            {
                it++;
            }
        }

        if ( it != string::npos )
        {
            count++;
        }
    }
    return count;
}

int numMatchingSubseq2( string S, vector<string>& words )
{
    vector< list<pair<int, int>> > wordMap( 26 );

    for ( int i = 0; i < words.size(); i++ )
    {
        wordMap[ words[i][0] - 'a' ].emplace_back( make_pair(i, 0) );
    }

    // cout << "end" << endl;

    for ( char c : S )
    {
        int size = wordMap[c - 'a'].size();

        for(int i = 0; i < size; i++)
        {
            int pos = wordMap[c - 'a'].front().first;
            int idx = wordMap[c - 'a'].front().second;
            
            wordMap[c - 'a'].pop_front();

            if ( idx + 1 < words[pos].length() )
            {
                wordMap[ words[pos][idx+1] - 'a' ].emplace_back( make_pair( pos, idx + 1 ) );
            }
        }
    }

    int count = 0;

    for ( auto i : wordMap )
    {
        count += i.size();
    }

    return words.size() - count;
}