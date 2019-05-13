/*
Remove the minimum number of invalid parentheses in 
order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>

/*
** BRUTE FORCE
std::vector<std::string> removeInvalidParenthesis( std::string s );
bool checkValid( std::string s, int skipIdx );
*/

std::vector<std::string> removeInvalidParenthesis( std::string s );
void helper( std::string s, int index, int leftCount, int rightCount, int leftRem, int rightRem, std::string temp, std::set<std::string>& validExp );

int main(int argc, char const *argv[])
{
    // std::string s = "()())()";
    // std::string s = "(a)())()";
    // std::string s = ")(";
    std::vector<std::string> result = removeInvalidParenthesis( s );
    
    for( std::string s : result )
    {
        std::cout << s << '\n';
    }
    return 0;
}

std::vector<std::string> removeInvalidParenthesis( std::string s )
{
    int left = 0;
    int right = 0;

    for( auto& c : s )
    {
        if( c == '(' )
        {
            left++;
        }
        else if( c == ')' )
        {
            left > 0 ? left-- : right++;
        }
    }

    std::set<std::string> validExp;

    helper( s, 0, 0, 0, left, right, "", validExp );
    return std::vector<std::string>( validExp.begin(), validExp.end() );
}

void helper( std::string s, int index, int leftCount, int rightCount, int leftRem, int rightRem, std::string temp, std::set<std::string>& validExp )
{
    // Check if we are at end of our string
    if( index == s.length() )
    {
        if( leftRem == 0 && rightRem == 0 )
        {
            validExp.insert( temp );
        }
    }
    else
    {
        char c = s[index];

        // Only recurse if it's required
        if( ( c == '(' && leftRem > 0 ) )
        {
            helper( s, index + 1, leftCount, rightCount, leftRem - 1, rightRem, temp, validExp );
        }
        else if ( ( c == ')' && rightRem > 0 ) )
        {
            helper( s, index + 1, leftCount, rightCount, leftRem, rightRem - 1, temp, validExp );
        }

        temp += c;

        // If it's not a character
        if( c != '(' && c != ')' )
        {
            helper( s, index + 1, leftCount, rightCount, leftRem, rightRem, temp, validExp );
        }
        else if( c == '(' )
        {
            // If its opening bracket
            helper(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, temp, validExp );
        }
        else if( rightCount < leftCount )
        {
            // If its closing bracket
            helper(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, temp, validExp );
        }

        temp.erase( temp.length() - 1 );
    }
    
}


/*
** BRUTE FORCE

std::vector<std::string> removeInvalidParenthesis( std::string s )
{
    std::vector<std::string> result;
    std::set<std::string> uniqueCombo;

    for( int i = 0; i < s.length(); i++ )
    {
        if( checkValid( s, i ) )
        {
            std::string temp = s;
            uniqueCombo.insert( temp.erase( i, 1 ) );
        }
    }
    return std::vector<std::string>( uniqueCombo.begin(), uniqueCombo.end() );
}

bool checkValid( std::string s, int skipIdx )
{
    std::stack<char> stack;

    for( int i = 0; i < s.length(); i++ )
    {
        if( i == skipIdx )
            continue;
        
        if( s[i] == '(' )
        {
            stack.push( s[i] );
        }
        else if( s[i] == ')' )
        {
            if( stack.empty() )
            {
                return false;
            }
            stack.pop();
        }
    }
    return stack.size() == 0;
}
*/