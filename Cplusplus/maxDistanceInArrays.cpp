#include <iostream>
#include <vector>

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int maxDistance(VVI &arrays);

int main()
{
    VVI arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    std::cout << maxDistance(arrays) << '\n';
    return 0;
}

int maxDistance(VVI &arrays)
{
    int min_val = arrays[0][0];
    int max_val = arrays[0][arrays[0].size() - 1];
    int dist = 0;

    for (int i = 1; i < arrays.size(); i++)
    {
        dist = std::max(dist, std::max(abs(arrays[i][arrays[i].size() - 1] - min_val), abs(max_val - arrays[i][0])));
        min_val = std::min(min_val, arrays[i][0]);
        max_val = std::max(max_val, arrays[i][arrays[i].size() - 1]);
    }
    return dist;
}