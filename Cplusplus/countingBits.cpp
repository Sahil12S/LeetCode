#include <iostream>
#include <vector>
#include <map>

#define FORI(s, n) for (int i = s; i <= n; i++)
#define FORJ(s, n) for (int j = s; j > n; j--)

using VI = std::vector<int>;
// using VVI = std::vector<VI>;

VI countBits(int num);

int main()
{
    int num = 5;
    VI ans = countBits(num);

    for (auto n : ans)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}

VI countBits(int num)
{
    VI result(num + 1);
    // FORI(0, num)
    // {
    //     result[i] = __builtin_popcount(i);
    // }

    int i = 0;
    int b = 1;
    while (b <= num)
    {
        while (i < b && i + b <= num)
        {
            result[i + b] = result[i] + 1;
            ++i;
        }
        i = 0;
        b *= 2;
        // std::cout << b << '\n';
    }

    return result;
}