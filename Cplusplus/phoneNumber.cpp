// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<string> letterCombinations(string digits);
void helperRecursive (string phone_num, int digit, string& temp_num, vector<string>* ans);
// void helperIterative (string phone_num, vector<string>* ans);

int main(int argc, char const *argv[])
{
    string number = "23";
    vector<string> ans = letterCombinations(number);
    for (string numbers : ans)
    {
        cout << numbers << " ";
    }
    cout << endl;
    return 0;
}

const vector<string> letters = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string str(digits.size(), '0');
    helperRecursive(digits, 0, str, &ans);
    return ans;
}

void helperRecursive (string phone_num, int digit, string& temp_num, vector<string>* ans)
{
    if (digit == phone_num.size())
    {
        ans->emplace_back(temp_num);
    }
    else
    {
        string alpha = letters[phone_num[digit] - '0'];

        for (char c : alpha)
        {
            temp_num[digit] = c;
            helperRecursive(phone_num, digit + 1, temp_num, ans);
        }
    }
    
}


// vector<string> helperIterative (string phone_num)
// {
//     // Count how many 7s and 9s
//     int count = 0;
//     for (char c : phone_num)
//     {
//         if (c == '7' || c == '9')
//         {
//             count++;
//         }
//     }

//     int sizeFour = count;
//     int sizeThree = phone_num.length() - count;

//     vector<string> ans((pow(3, sizeThree) * pow(4, sizeFour)), "");

//     for (int digit = 0; digit < phone_num.length(); digit++)
//     {
//         string alpha = letters[phone_num[digit] - '0'];
//         // string temp(phone_num.length(), 0);
//         int index = digit * alpha.size();

//         for (char c : alpha)
//         {
//             for (int i = 0; i < phone_num.length(); i++)
//             {
//                 ans[i] += c;
//             }
//         }
//     }
// }