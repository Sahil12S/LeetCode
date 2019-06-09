/**
 * Given words first and second, consider occurrences in some text of the form "first second third",
 * where second comes immediately after first, and third comes immediately after second.
 * 
 * For each such occurrence, add "third" to the answer, and return the answer.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using VS = std::vector<std::string>;

VS findOcurrences(std::string text, std::string first, std::string second);

int main()
{
    // std::string text = "alice is a good girl she is a good student";
    // std::string first = "a";
    // std::string second = "good";
    // std::string text = "we will we will rock you";
    // std::string first = "we";
    // std::string second = "will";
    std::string text = "lnlqhmaohv ypkk";
    std::string first = "lnlqhmaohv";
    std::string second = "ypkk";
    // std::string text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa";
    // std::string first = "kcyxdfnoa";
    // std::string second = "jkypmsxd";
    auto res = findOcurrences(text, first, second);
    std::cout << '\n';
    for (auto word : res)
    {
        std::cout << word << '\n';
    }
    return 0;
}
VS findOcurrences(std::string text, std::string first, std::string second)
{
    std::stringstream ss(text);
    std::string str;
    VS words = {first, second};
    int position = 0;
    VS res;

    while (ss >> str)
    {
        // Check for third word
        if (position == 2)
        {
            res.emplace_back(str);
            position = 0;
        }

        // Check if word at current position matches either first or second
        if (str == words[position])
        {
            position++;
        }
        else
        {
            // If second is not a match, check if first is match
            position = 0;
            if (str == words[position])
            {
                position++;
            }
        }
    }
    return res;
}