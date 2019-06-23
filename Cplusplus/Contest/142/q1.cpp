#include <iostream>
#include <vector>
#include <limits>

#define FORI(s, n) for (int i = s; i < n; i++)

using VD = std::vector<double>;
using VI = std::vector<int>;

std::vector<double> sampleStats(std::vector<int> &count);

int main(int argc, char const *argv[])
{
    VI count = {0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    VD ans = sampleStats(count);
    std::cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << '\n';

    return 0;
}

std::vector<double> sampleStats(std::vector<int> &count)
{
    // std::sort(count.begin(), count.end());

    double minVal = 256;
    double maxVal = -1;
    double mean;
    double median;
    double mode;
    int maxCount = 0;

    int totalCount = 0;
    double sum = 0;

    FORI(0, count.size())
    {
        if (count[i] > 0 && i < minVal)
        {
            minVal = i;
        }
        if (count[i] > 0 && i > maxVal)
        {
            maxVal = i;
        }

        if (count[i] > maxCount)
        {
            maxCount = count[i];
            mode = i;
        }
        totalCount += count[i];
        sum += count[i] * i;
    }

    mean = sum / static_cast<double>(totalCount);

    // for finding median
    int c1 = totalCount / 2;
    int curr = 0;

    // totalCount = 0;

    int i = 0;

    while (curr < c1)
    {
        curr += count[i++];
    }
    i--;

    if (totalCount % 2 == 0)
    {
        if (curr == c1)
        {
            median = (i + i + 1) / 2;
        }
        else
        {
            median = i;
        }
    }
    else
    {
        median = i;
    }

    return {minVal, maxVal, mean, median, mode};
}