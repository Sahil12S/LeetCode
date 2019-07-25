#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int minTransfers(VVI &transactions);
int dfs(int idx, std::vector<long> &debts);

int main()
{
    VVI transactions = {{0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}};
    std::cout << minTransfers(transactions) << '\n';
    return 0;
}

int minTransfers(VVI &transactions)
{
    std::unordered_map<int, long> balance;
    for (auto t : transactions)
    {
        balance[t[0]] -= t[2];
        balance[t[1]] += t[2];
    }

    std::vector<long> debts;
    for (auto it : balance)
    {
        if (it.second)
        {
            debts.push_back(it.second);
        }
    }

    return dfs(0, debts);
}

int dfs(int idx, std::vector<long> &debts)
{
    if (idx < debts.size() && debts[idx] == 0)
    {
        idx++;
    }

    int t_count = std::numeric_limits<int>::max();

    for (int i = idx + 1, prev = 0; i < debts.size(); i++)
    {
        if (debts[i] != prev && debts[i] * debts[idx] < 0)
        {
            debts[i] += debts[idx];
            t_count = std::min(t_count, 1 + dfs(idx + 1, debts));
            prev = debts[i] - debts[idx];
        }
    }
    return t_count < std::numeric_limits<int>::max() ? t_count : 0;
}