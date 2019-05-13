// Main file to run other files

#include "Headers.h"

int main(int argc, char const *argv[])
{
    LeetCode obj;

    // Question: 076    File: minWindowSubstring.cpp
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    // std::string s = "a";
    // std::string t = "aa";
    std::string result = obj.minWindow( s, t );
    std::cout << result << std::endl;

    return 0;
}
