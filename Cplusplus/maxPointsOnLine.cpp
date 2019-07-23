/**
 * Given n points on a 2D plane,
 * find the maximum number of points that lie on the same straight line.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <numeric>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int maxPoints(VVI &points);
int gcd(int x, int y);

int main()
{
    VVI points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    // VVI points = {{1, 1}, {2, 2}, {3, 3}, {1, 1}};
    // VVI points = {{0, 0}, {94911151, 94911150}, {94911152, 94911151}};
    std::cout << maxPoints(points) << '\n';
    return 0;
}

int maxPoints(VVI &points)
{
    if (points.empty())
    {
        return 0;
    }

    std::string INF = "INF";

    int max_count = 0;
    FORI(0, points.size())
    {
        std::unordered_map<std::string, int> slope_map;
        int same_count = 1;
        int curr_max = 0;
        FORJ(i + 1, points.size())
        {
            int x = points[j][0] - points[i][0];
            int y = points[j][1] - points[i][1];
            // int x = points[i][0] - points[j][0];
            // int y = points[i][1] - points[j][1];
            std::string key;
            if (x == 0 && y == 0)
            {
                same_count++;
                continue;
            }
            else if (x == 0)
            {
                key = INF;
            }
            else
            {
                int d = gcd(x, y);
                if (d != 0)
                {
                    x /= d;
                    y /= d;
                }

                key = std::to_string(x) + std::to_string(y);
            }
            slope_map[key]++;
            curr_max = std::max(curr_max, slope_map[key]);
        }
        max_count = std::max(max_count, curr_max + same_count);
    }
    return max_count;
}

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}