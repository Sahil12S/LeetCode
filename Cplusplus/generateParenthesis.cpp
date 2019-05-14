// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#include <iostream>
#include <vector>

std::vector<std::string> generateParenthesis( int n );
void backtrack( std::vector<std::string>& ans, std::string curr, int open, int close, int n );

int main(int argc, char const *argv[])
{
    int n = 3;
    std::vector<std::string> result = generateParenthesis( n );
    
    for( auto s : result )
    {
        std::cout << s << '\n';
    }
    return 0;
}


std::vector<std::string> generateParenthesis( int n )
{
    std::vector<std::string> ans;

    backtrack( ans, "", 0, 0, n );
    return ans;
}

void backtrack( std::vector<std::string>& ans, std::string curr, int open, int close, int n )
{
    if( curr.length() == n * 2 )
    {
        ans.emplace_back( curr );
        return;
    }

    if( open < n )
    {
        backtrack( ans, curr + "(", open + 1, close, n );
    }
    if ( close < open )
    {
        backtrack( ans, curr + ")", open, close + 1, n );
    } 
}