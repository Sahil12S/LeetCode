/**
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 */

#include <iostream>
#include <vector>
#include <map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

std::string fractionToDeciaml(int numerator, int denominator);

int main()
{
    int numerator = 2;
    int denominator = 3;
    std::cout << fractionToDeciaml(numerator, denominator) << '\n';
    return 0;
}

std::string fractionToDeciaml(int numerator, int denominator)
{
    if (numerator == 0)
    {
        return "0";
    }

    std::string ans = "";

    if (numerator < 0 ^ denominator < 0)
    {
        ans += '-';
    }

    // Converting numerator and denominator to Long to prevent any overflow
    long dividend = std::abs(static_cast<long>(numerator));
    long divisor = std::abs(static_cast<long>(denominator));

    ans += std::to_string(dividend / divisor);

    long remainder = dividend % divisor;

    if (remainder == 0)
    {
        return ans;
    }

    ans += '.';

    // Map to keep track of occuring remainder
    // Stores remainder and length of result at that time
    std::map<long, int> remMap;
    while (remainder != 0)
    {
        if (remMap.find(remainder) != remMap.end())
        {
            ans.insert(remMap[remainder], "(");
            ans += ')';
            break;
        }
        remMap[remainder] = ans.size();
        remainder *= 10;
        ans += std::to_string(remainder / divisor);
        remainder %= divisor;
    }
    return ans;
}