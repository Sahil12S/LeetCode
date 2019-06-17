#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define FORI(s, n) for (int i = s; i < n; i++)

using VI = std::vector<int>;

int lengthLongestPath(std::string input);

int main()
{
    std::string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    std::cout << lengthLongestPath(input) << '\n';
    return 0;
}

int lengthLongestPath(std::string input)
{
    VI dirs(256, 0);
    int res = 0;
    int len = 0;
    int level = 0;
    bool isFile = false;
    input.push_back('\n');

    FORI(0, input.size())
    {
        switch (input[i])
        {
        case '\n':
            len = 0;
            level = 0;
            isFile = false;
            break;
        case '\t':
            level++;
            break;
        case '.':
            isFile = true;
        default:
            len++;
            dirs[level] = len;
            if (isFile)
            {
                res = std::max(res, std::accumulate(dirs.begin(), dirs.begin() + level + 1, 0) + level);
            }
        }
    }

    return res;
}