#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)

using VS = std::vector<std::string>;
using VC = std::vector<char>;
using VVC = std::vector<VC>;

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VS expand(std::string S);
void backtrack(VS &res, std::string temp, VVC all_chars, int idx);

int main()
{
    // std::string S = "{a,b,c}d{e,f}";
    std::string S = "{a,b}{z,x,y}";
    // std::string S = "{a,b}c{d,e}f";
    // std::string S = "abcd";
    VS res = expand(S);

    for (auto s : res)
    {
        std::cout << s << '\n';
    }
    return 0;
}

VS expand(std::string S)
{
    VVC all_chars;

    bool open = false;
    for (char c : S)
    {
        switch (c)
        {
        case '{':
            all_chars.push_back({});
            open = true;
            break;
        case '}':
            open = false;
            break;
        case ',':
            // all_chars.back().push_back(c);
            break;
        default:
            if (open)
            {
                all_chars.back().push_back(c);
            }
            else
            {
                all_chars.push_back({c});
            }
        }
    }

    VS res;

    backtrack(res, "", all_chars, 0);

    std::sort(res.begin(), res.end());

    return res;
}

void backtrack(VS &res, std::string temp, VVC all_chars, int idx)
{
    if (idx == all_chars.size())
    {
        res.push_back(temp);
        return;
    }

    for (auto c : all_chars[idx])
    {
        backtrack(res, temp + c, all_chars, idx + 1);
    }
}