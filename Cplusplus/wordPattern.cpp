/**
 * Given a pattern and a string str, find if str follows the same pattern.
 */

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

bool wordPattern(std::string pattern, std::string str);

int main()
{
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    std::cout << wordPattern(pattern, str) << '\n';
    return 0;
}

bool wordPattern(std::string pattern, std::string str)
{
    if (pattern.size() == 0 && str.size() == 0)
    {
        return true;
    }
    else if (pattern.size() == 0 && str.size() == 0)
    {
        return false;
    }
    std::map<std::string, char> m1;
    std::map<char, std::string> m2;

    std::istringstream ss(str);
    std::string tempstr;
    int i = 0;
    while (ss >> tempstr)
    {
        if (i == pattern.size())
        {
            return false;
        }
        if (m1.find(tempstr) != m1.end() || m2.find(pattern[i]) != m2.end())
        {
            if (m1[tempstr] != pattern[i] || m2[pattern[i]] != tempstr)
            {
                return false;
            }
        }
        else
        {
            m1[tempstr] = pattern[i];
            m2[pattern[i]] = tempstr;
        }
        i++;
    }

    return i == pattern.size();
}