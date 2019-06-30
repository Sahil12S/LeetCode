#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VS = std::vector<std::string>;
using VI = std::vector<int>;
using VVI = std::vector<VI>;

VS generatePossibleNextMoves(std::string s);

int main()
{
    // std::string s = "++++";
    // std::string s = "--";
    // std::string s = "+";
    std::string s = "++-+";
    VS res = generatePossibleNextMoves(s);
    for (auto w : res)
    {
        std::cout << w << '\n';
    }
    return 0;
}

VS generatePossibleNextMoves(std::string s)
{
    VS res;
    if (s.empty())
    {
        return res;
    }
    std::string temp = s;

    FORI(0, s.size() - 1)
    {
        if (temp[i] == '+' && temp[i + 1] == '+')
        {
            res.push_back(temp);
            res.back()[i] = '-';
            res.back()[i + 1] = '-';
        }
    }

    return res;
}