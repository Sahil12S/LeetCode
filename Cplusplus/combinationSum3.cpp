#include <iostream>
#include <vector>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

VVI combinationSum3(int k, int n);
void backtrack(VVI &res, VI temp, int size, int target, int idx);

int main()
{
    int k = 3;
    int n = 7;
    VVI ans = combinationSum3(k, n);
    for (auto comb : ans)
    {
        for (auto s : comb)
        {
            std::cout << s;
        }
        std::cout << '\n';
    }
    return 0;
}

VVI combinationSum3(int k, int n)
{
    VVI res;
    backtrack(res, {}, k, n, 1);
    return res;
}

void backtrack(VVI &res, VI temp, int k, int n, int idx)
{
    if (temp.size() == k && n == 0)
    {
        res.push_back(temp);
        return;
    }

    FORI(idx, 10)
    {
        if (idx > n)
        {
            return;
        }
        temp.push_back(i);
        backtrack(res, temp, k, n - i, i + 1);
        temp.pop_back();
    }
}