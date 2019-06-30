#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i <= n; i++)
#define FORJ(s, n) for (int j = s; j <= n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VVI combinations(int n, int k);
void backtrack(VVI &res, VI temp, int n, int k, int idx);

int main()
{
    int n = 4;
    int k = 2;
    auto res = combinations(n, k);
    for (auto w : res)
    {
        for (auto x : w)
        {
            std::cout << x << " ";
        }
        std::cout << '\n';
    }
    return 0;
}

VVI combinations(int n, int k)
{
    VVI res;
    backtrack(res, {}, n, k, 1);

    return res;
}

void backtrack(VVI &res, VI temp, int n, int k, int idx)
{
    if (temp.size() == k)
    {
        res.push_back(temp);
    }
    else
    {
        FORI(idx, n)
        {
            temp.push_back(i);
            backtrack(res, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
}