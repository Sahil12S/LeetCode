/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
*/

#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs);

int main()
{
    std::vector<std::string> strs = {"flower", "flow", "flight"};

    std::cout << longestCommonPrefix(strs) << '\n';
    return 0;
}

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    std::string prefix = strs[0];

    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i].size() < prefix.size())
        {
            prefix = strs[i];
        }
    }

    int size = prefix.size();
    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i].substr(0, size) != prefix)
        {
            while (strs[i].substr(0, size) != prefix)
            {
                prefix = prefix.substr(0, size - 1);
                size = prefix.length();
                if (prefix == "")
                    return "";
            }
        }
    }
    return prefix;
}