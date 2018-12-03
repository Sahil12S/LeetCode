#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned);


int main(int argc, char const *argv[])
{
    string paragraph = "Bob";
    vector<string> banned = {""};
    cout << mostCommonWord(paragraph, banned) << endl;
    return 0;
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    map<string, int> wordCount;
    map<string, int>::iterator it;

    string word;
    for (char c : paragraph) {
        if (isalpha(c)) {
            if (c >= 65 && c <= 90 ) {
                c += 32;
            }
            word += c;
        } else if (word.length() > 0) {
            cout << "word:" << word << "<-" << endl;
            it = wordCount.find(word);
            if (it != wordCount.end()) {
                ++it->second;
            } else {
                wordCount[word] = 1;
            }
            word = "";
        }
    }

    for (string w : banned) {
        wordCount.erase(w);
    }

    it = wordCount.begin();
    string ans;
    int maxCount = 0;
    while (it != wordCount.end()) {
        // cout << "map: " << it->first << endl;
        if (it->second > maxCount) {
            maxCount = it->second;
            ans = it->first;
            // cout << "ans is: " << ans << endl;
        }
        ++it;
    }
    return ans;
}