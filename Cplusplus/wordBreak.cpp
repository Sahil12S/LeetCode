/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

bool wordBreak( std::string s, std::vector<std::string>& wordDict );


int main(int argc, char const *argv[])
{
    // std::string s = "leetcode";
    // std::vector<std::string> wordDict = { "leet", "code" };
    std::string s = "applepenapple";
    std::vector<std::string> wordDict = { "apple", "pen" };
    std::cout << wordBreak( s, wordDict ) << '\n';
    return 0;
}

bool wordBreak( std::string s, std::vector<std::string>& wordDict )
{
    // Store all unique words from dictionary
    std::unordered_set<std::string> wordSet;

    for( auto word : wordDict )
    {
        wordSet.insert( word );
    }

    std::queue<int> q; // Store indices where we find matches
    std::vector<bool> visited( s.length(), false );    // Keep track of visited letters

    q.push( 0 );    // Store starting index

    while( !q.empty() )
    {
        int start = q.front();
        q.pop();

        // To see if we haven't already checked the word
        if( !visited[start] )
        {
            for( int end = start + 1; end <= s.length(); end++ )
            {
                // Check if the word exist
                if( wordSet.count( s.substr( start, ( end - start ) ) ) )
                {
                    // Push index from where we have to start next word
                    q.push( end );
                    if( end == s.length() )
                    {
                        return true;
                    }
                }
            }
        }
        visited[start] = true;
    }
    return false;
}