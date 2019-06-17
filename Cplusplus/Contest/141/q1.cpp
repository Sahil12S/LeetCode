#include <iostream>
#include <vector>
#include <limits>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

#define INF std::numeric_limits<int>::max()

using VI = std::vector<int>;
using VVI = std::vector<VI>;

void duplicateZeros(VI &arr);

int main()
{
    // VI arr = {1, 0, 2, 3, 0, 4, 5, 0};
    // VI arr = {1, 2, 3};
    VI arr = {8, 4, 5, 0, 0, 0, 0, 7};
    duplicateZeros(arr);
    for (auto a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';
    return 0;
}
void duplicateZeros(VI &arr)
{
    if (arr.empty())
    {
        return;
    }

    VI temp(arr.size());
    int j = 0;
    FORI(0, arr.size())
    {
        if (j >= arr.size())
        {
            break;
        }
        if (arr[i] == 0)
        {
            temp[j++] = 0;
            temp[j++] = 0;
        }
        else
        {
            temp[j++] = arr[i];
        }
        // std::cout << temp[j] << '\n';
    }

    FORI(0, arr.size())
    {
        arr[i] = temp[i];
    }
    for (auto a : temp)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';
    // arr = std::move(temp);
}