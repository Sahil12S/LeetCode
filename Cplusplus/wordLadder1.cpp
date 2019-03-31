/*
Given two words (beginWord and endWord), and a dictionary's word list,
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int ladderLength( string beginWord, string endWord, vector<string>& wordList );

int visit( unordered_map<string, vector<string>>& buckets, int L, queue< pair<string, int>>& Q, 
                        unordered_map<string, int>& visited, unordered_map<string, int>& otherVisited );

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    cout << ladderLength( beginWord, endWord, wordList ) << endl;
    return 0;
}
/*

int ladderLength( string beginWord, string endWord, vector<string>& wordList )
{
    // Check if any parameter is empty
    if ( !beginWord.length() || !endWord.length() || !wordList.size() )
    {
        return 0;
    }

    int L = beginWord.length();

    // map of list
    // Key are words with one letter being wildcard
    // Values are list of words that matches that pattern.
    unordered_map<string, vector<string>> buckets;

    for ( string word : wordList )
    {
        for ( int i = 0; i < L; i++ )
        {
            string bucket = word;
            bucket[i] = '_';
            buckets[bucket].emplace_back( word );
        }
    }

    // for ( auto it : buckets )
    // {
    //     cout << it.first << "-" << it.second.size() << endl;
    // }

    // Queue to store word and its level
    queue< pair<string, int>> Q;
    // Store visited words
    set<string> visited;

    Q.push( make_pair( beginWord, 1 ) );
    visited.emplace( beginWord );

    while ( !Q.empty() )
    {
        string curr_word = Q.front().first;
        int level = Q.front().second;
        Q.pop();

        // cout << "curr: " << curr_word << endl;

        for ( int i = 0; i < L; i++ )
        {
            string bucket = curr_word;
            bucket[i] = '_';
            // cout << "bucket: " << bucket << endl;
            if ( buckets.count( bucket ) == 0 )
            {
                continue;
            }
            for ( string word : buckets[bucket] )
            {
                if ( word == endWord )
                {
                    return level + 1;
                }

                if ( visited.count( word ) == 0 )
                {
                    cout << word << endl;
                    visited.emplace( word );
                    Q.push( make_pair( word, level + 1 ) );
                }
            }
            buckets[bucket] = {};
        }
        // cout << "------" << endl;
    }

    return 0;
}

*/

int ladderLength( string beginWord, string endWord, vector<string>& wordList )
{
    // Check if any parameter is empty
    if ( !beginWord.length() || !endWord.length() || !wordList.size() )
    {
        return 0;
    }
    if ( find( wordList.begin(), wordList.end(), endWord ) == wordList.end() )
    {
        return 0;
    }

    int L = beginWord.length();

    // map of list
    // Key are words with one letter being wildcard
    // Values are list of words that matches that pattern.
    unordered_map<string, vector<string>> buckets;

    for ( string word : wordList )
    {
        for ( int i = 0; i < L; i++ )
        {
            string bucket = word;
            bucket[i] = '_';
            buckets[bucket].emplace_back( word );
        }
    }

    // Queue to store word and its level
    queue< pair<string, int>> beginWordQ;
    queue< pair<string, int>> endWordQ;
    // Store visited words
    unordered_map<string, int> beginWordVisited;
    unordered_map<string, int> endWordVisited;

    beginWordQ.push( make_pair( beginWord, 1 ) );
    endWordQ.push( make_pair( endWord, 1 ) );

    beginWordVisited[beginWord] = 1;
    endWordVisited[endWord] = 1;

    // int ans = 0;

    while ( !beginWordQ.empty() && !endWordQ.empty() )
    {
        cout << "begin" << endl;
        int ans = visit( buckets, L, beginWordQ, beginWordVisited, endWordVisited );
        if ( ans > -1 )
        {
            return ans;
        }
        
        cout << "end" << endl;
        ans = visit( buckets, L, endWordQ, endWordVisited, beginWordVisited );
        if ( ans > -1 )
        {
            return ans;
        }
    }
    return 0;
}

int visit( unordered_map<string, vector<string>>& buckets, int L, queue< pair<string, int>>& Q, 
                        unordered_map<string, int>& visited, unordered_map<string, int>& otherVisited )
{
    string curr_word = Q.front().first;
    int level = Q.front().second;
    Q.pop();


    for ( int i = 0; i < L; i++ )
    {
        string bucket = curr_word;
        bucket[i] = '_';
        // cout << "bucket: " << bucket << endl;
        if ( buckets.count( bucket ) == 0 )
        {
            continue;
        }
        for ( string word : buckets[bucket] )
        {
            // cout << word << endl;
            if ( otherVisited.count( word ) != 0 )
            {
                return level + otherVisited[word];
            }

            if ( visited.count( word ) == 0 )
            {
                cout << word << endl;
                visited[word] = level + 1;
                Q.push( make_pair( word, level + 1 ) );
            }
        }
        buckets[bucket] = {};
    }
    return -1;
}