#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using VS = std::vector<std::string>;

VS reorderLogFiles(VS &logs);

int main()
{
    // VS logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    VS logs = {"j je", "b fjt", "7 zbr", "m le", "o 33"};
    reorderLogFiles(logs);
    for (auto log : logs)
    {
        std::cout << log << '\n';
    }
    return 0;
}

bool compare(std::string s1, std::string s2)
{
    std::string key1;
    std::string rem1;
    int i = 0;
    while (s1[i] != ' ')
    {
        i++;
    }
    key1 = s1.substr(0, i);
    rem1 = s1.substr(i + 1);

    std::string key2;
    std::string rem2;
    i = 0;
    while (s2[i] != ' ')
    {
        i++;
    }
    key2 = s2.substr(0, i);
    rem2 = s2.substr(i + 1);
    std::cout << rem1 << ' ' << rem2 << '\n';
    if (!std::isdigit(rem1[0]) && !std::isdigit(rem2[0]))
    {
        if (rem1 < rem2)
        {
            std::cout << "less" << '\n';
            return true;
        }
        else if (rem1 > rem2)
        {
            std::cout << "greater" << '\n';
            return false;
        }
        else
        {
            std::cout << "equal" << '\n';
            return key1 < key2;
        }
    }
    else
    {
        if (!std::isdigit(rem1[0]))
        {
            return true;
        }
        return false;
    }
}

VS reorderLogFiles(VS &logs)
{
    std::stable_sort(logs.begin(), logs.end(), compare);

    return logs;
}