// Return list of unique substring from a given sentence

#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

vector<string> findUnique(string word, int K);
void print(vector<string> values);

int main(int argc, char const *argv[])
{
    string word = "abcdedefghi";
    print(findUnique(word, 3));
    return 0;
}

vector<string> findUnique(string word, int K)
{
    int i = 0, iter = i;
    vector<string> sol;
    vector<char> chars(26, 0);
    set<string> ans;
    string str = "";

    int count = 0;

    while (iter < word.length() && count < 20)
    {
        while ((iter - i) < K)
        {
            if (chars[word[iter] - '0'] == 0)
            {
                chars[word[iter] - '0']++;
                str += word[iter];
            }
            else
            {
                chars[word[iter] - '0']--;
                i++;
            }
            iter++;
            cout << i << ", " << iter << endl;
        }
        cout << str << endl;
        
        if (str.length() == 3 && ans.count(str) == 0)
        {
            cout << "insert" << endl;
            ans.insert(str);
            str = str.substr(1);
            chars[word[iter-1] - '0']--;
        }
        i++, iter++;
        count++;
    }

    // int count = 0;

    
    auto iterator = ans.begin();

    while (iterator != ans.end())
    {
        cout << *iterator << endl;
        sol.push_back(*iterator);
        iterator++;
    }

    return sol;
}

void print(vector<string> values)
{
    for (string val : values)
    {
        // cout << val << endl;
    }
}