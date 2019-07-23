/**
 * Given an integer n, find the closest integer (not including itself), which is a palindrome.
 *
 * The 'closest' is defined as absolute difference minimized between two integers.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using VI = std::vector<int>;
using VVI = std::vector<VI>;

std::string nearestPalindromic(std::string n);
bool allNines(std::string n);
long createPalindrome(std::string root, bool even_size);

int main()
{
    // std::string n = "100001";
    // std::string n = "99999";
    std::string n = "55499";
    std::cout << nearestPalindromic(n) << '\n';
    return 0;
}

std::string nearestPalindromic(std::string n)
{
    long num = std::stol(n);

    // Edge Cases
    // Case 1: n is 10, 100, 1000, 10000, ...
    // We subtract 1 to get closest palindrome (preferring lower in case of tie)
    if (num <= 10 || (n[0] == '1' && std::stol(n.substr(1)) == 0))
    {
        return std::to_string(num - 1);
    }

    // Case 2: n is 11, 101, 1001, 10001, ...
    // We subtract 2 to get to closest palindrome
    if (num == 11 || (n[0] == '1' && num % 10 == 1 && std::stol(n.substr(1, n.size() - 2)) == 0))
    {
        return std::to_string(num - 2);
    }

    // Case 3: n is 99, 999, 9999, 99999, ...
    // We add 2 get to closest palindrome
    if (num == 99 || (num % 10 == 9 && n[0] == '9' && allNines(n)))
    {
        return std::to_string(num + 2);
    }

    // Now there could be 3 nearest palindrome number
    // If first half of string is palindrome root
    // for ex. n = 12345, root = 123
    // Now lower number would be fromed by 122 => 12221
    // Now higher number would be fromed by 124 => 12421
    // And one number formed by root itself 123 => 12321
    // Now we find the closes one
    bool evenSize = n.size() % 2 == 0;
    long root = std::stol(n.substr(0, (n.size() + 1) / 2));
    // std::cout << root << '\n';

    long lowerNum = createPalindrome(std::to_string(root - 1), evenSize);
    long higherNum = createPalindrome(std::to_string(root + 1), evenSize);
    long selfNum = createPalindrome(std::to_string(root), evenSize);
    // std::cout << lowerNum << '\n';
    // std::cout << higherNum << '\n';
    // std::cout << selfNum << '\n';

    long diffH = std::abs(higherNum - num);
    long diffL = std::abs(lowerNum - num);
    long diffS = std::abs(selfNum - num);

    long closestNum = diffH < diffL ? higherNum : lowerNum;

    // In case of tie, we take smaller one
    long minDiff = std::min(diffH, diffL);

    // If n is not a palindrome
    if (diffS != 0)
    {
        if (diffS == minDiff)
        {
            closestNum = std::min(selfNum, closestNum);
        }
        else if (diffS < minDiff)
        {
            closestNum = selfNum;
        }
    }

    return std::to_string(closestNum);
}

bool allNines(std::string n)
{
    // if all other digits are 9
    for (int i = 1; i < n.size() - 1; i++)
    {
        if (n[i] != '9')
        {
            return false;
        }
    }
    return true;
}

long createPalindrome(std::string root, bool even_size)
{
    std::string reversed = root;
    std::reverse(reversed.begin(), reversed.end());

    if (even_size)
    {
        root += reversed;
        // std::cout << root << '\n';
    }
    else
    {
        root += reversed.substr(1);
    }

    return std::stol(root);
}