/**
 * A binary watch has 4 LEDs on the top which represent the hours (0-11),
 * and the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the right.
 */

#include <iostream>
#include <vector>

std::vector<std::string> readBinaryWatch(int num);
std::vector<int> generateDigits(std::vector<int> vec, int count);
void helper(std::vector<int> vec, int count, int pos, int sum, std::vector<int> &res);

int main()
{
    int num = 1;
    std::vector<std::string> ans = readBinaryWatch(num);
    for (auto str : ans)
    {
        std::cout << str << '\n';
    }
    return 0;
}

std::vector<std::string> readBinaryWatch(int num)
{
    std::vector<int> hours = {1, 2, 4, 8};
    std::vector<int> minutes = {1, 2, 4, 8, 16, 32};
    std::vector<std::string> res;

    for (int i = 0; i <= num; i++)
    {
        std::vector<int> l1 = generateDigits(hours, i);
        std::vector<int> l2 = generateDigits(minutes, num - i);

        for (auto num1 : l1)
        {
            if (num1 >= 12)
                continue;
            for (auto num2 : l2)
            {
                if (num2 > 59)
                    continue;
                res.emplace_back(std::to_string(num1) + ":" + (num2 < 10 ? "0" + std::to_string(num2) : std::to_string(num2)));
            }
        }
    }

    return res;
}

std::vector<int> generateDigits(std::vector<int> vec, int count)
{
    std::vector<int> res;
    helper(vec, count, 0, 0, res);
    return res;
}

void helper(std::vector<int> vec, int count, int pos, int sum, std::vector<int> &res)
{
    if (count == 0)
    {
        res.emplace_back(sum);
        return;
    }

    for (int i = pos; i < vec.size(); i++)
    {
        helper(vec, count - 1, i + 1, sum + vec[i], res);
    }
}