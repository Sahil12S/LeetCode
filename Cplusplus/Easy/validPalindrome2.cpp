#include <iostream>
#include <string>

using namespace std;

// You can delete atmost 1 character to make string palindorme.
bool validPalindrome2(string s);
bool isPlaindrome(string s, int start, int end);

int main(int argc, char const *argv[])
{
    cout << validPalindrome2("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;
    return 0;
}

bool validPalindrome2(string s) {
    int i = 0, j = s.length() - 1;
    bool onceDeleted = false;

    while (i < j) {
        if (s[i] != s[j]) {
            return isPlaindrome(s, i+1, j) || isPlaindrome(s, i, j-1);
        }
        ++i, --j;
    }
    return true;
}

bool isPlaindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        ++start, --end;
    }
    return true;
}