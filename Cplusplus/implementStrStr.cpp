/**
 * Return the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 */

#include <iostream>

int strStr(std::string haystack, std::string needle);

int main()
{
    std::string haystack = "bbaaaaabba";
    std::string needle = "bba";
    std::cout << strStr(haystack, needle) << '\n';
    return 0;
}

int strStr(std::string haystack, std::string needle)
{
    if (needle.length() == 0)
    {
        return 0;
    }
    int idx = 0;
    for (int i = 0; i < haystack.length(); i++)
    {
        if (haystack.at(i) == needle.at(idx))
        {
            if (idx == needle.size() - 1)
            {
                return i - needle.size() + 1;
            }
            idx++;
        }
        else
        {
            i -= idx;
            idx = 0;
        }
    }
    return -1;
}