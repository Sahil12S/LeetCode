#include <iostream>
#include <vector>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VS = std::vector<std::string>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

bool canWin(std::string s);
bool backtrack(std::string s, std::unordered_map<std::string, bool> &mem);

int main()
{
    std::string s = "++++++";
    std::cout << canWin(s) << std::endl;
    return 0;
}

bool canWin(std::string s)
{
    if (s.empty())
    {
        return false;
    }
    std::unordered_map<std::string, bool> mem;
    return backtrack(s, mem);
}

bool backtrack(std::string s, std::unordered_map<std::string, bool> &mem)
{
    if (mem.count(s))
    {
        return mem[s];
    }

    FORI(0, s.length() - 1)
    {
        if (s[i] == '+' && s[i + 1] == '+')
        {
            std::string temp = s;
            temp[i] = '-';
            temp[i + 1] = '-';
            mem[s] = !backtrack(temp, mem);

            if (mem[s])
            {
                return true;
            }
        }
    }
    return false;
}