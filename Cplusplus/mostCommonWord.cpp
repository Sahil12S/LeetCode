// Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.

#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <map>
#include <set>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned);

int main(int argc, char const *argv[])
{
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit";
    // string paragraph = "Bob";
    vector<string> banned = {"hit"};
    cout << mostCommonWord(paragraph, banned) << endl;
    return 0;
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    map<string, int> wordCount;
    map<string, int>::iterator it;
    set<string> bannedWords;

    locale loc;

    for (string word : banned) {
        bannedWords.insert(word);
    }

    string tempWord = "";
    for (char c : paragraph) {
        if (!isalpha(c)) {
            // word is complete. store it.

            if (tempWord.length() <= 0) continue;

            if (bannedWords.count(tempWord) != 0) {
                tempWord = "";
                continue;
            }

            it = wordCount.find(tempWord);
            if (it != wordCount.end()) {
                it->second++;
            } else {
                wordCount[tempWord] = 1;
            }
            tempWord = "";
        } else {
            // Create a word by adding characters.
            tempWord += tolower(c);
        }
    }

    // Paragraph ends with an alphabet.
    if (tempWord.length() > 0) {
        // cout << bannedWords.count(tempWord) << endl;
        if (bannedWords.count(tempWord) == 0) {
            // cout << "tempWord: " << tempWord << endl;
            it = wordCount.find(tempWord);
            if (it != wordCount.end()) {
                it->second++;
            } else {
                wordCount[tempWord] = 1;
            }
            tempWord = "";
        }
    }

    string ans;
    int maxCount = 0;
    for (it = wordCount.begin(); it != wordCount.end(); ++it) {
        if (it->second > maxCount) {
            maxCount = it->second;
            ans = it->first;
            // cout << "ans: " << ans << ", maxCount: " << maxCount << endl;
        }
    }
    return ans;

}


