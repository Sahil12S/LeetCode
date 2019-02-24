// Given an input string, reverse the string word by word.

#include <iostream>
#include <algorithm>

using namespace std;

void reverseWords(string& s);
void reverse(string&s, int i, int j);

int main(int argc, char const *argv[])
{
    string sentence = "  how are you  ";
    reverseWords(sentence);
    cout << sentence << endl;
    return 0;
}

void reverseWords(string& s)
{
    // Reverse sentence while leaving leading multiple spaces at end
    int i = 0, j = 0;

    bool word = false;
    int index = 0;

    

    while (i < s.length() && j < s.length())
    {
        while (i < s.length() && s[i] == ' ')
        {
            i++;
        }
        if (i == s.length())
        {
            break;
        }
        if (word) s[j++] = ' ';
        index = j;
        

        while (i < s.length() && s[i] != ' ')
        {
            s[j] = s[i];
            i++, j++;
        }

        reverse(s, index, j - 1);
        word = true;
    }

    s.resize(j);
    reverse(s, 0, j - 1);
}

void reverse(string& s, int i, int j)
{
    while (i < j)
    {
        int temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}