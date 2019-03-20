#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string getHint(string secret, string guess);

int main(int argc, char const *argv[])
{
    cout << getHint("1807", "7810") <<  endl;
    return 0;
}


string getHint(string secret, string guess) {
    map<char, int> secret_map;
    map<char, int>::iterator it;

    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < secret.length(); ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
            // cout << guess.substr(0,i) << " & " << guess.substr(i, guess.length()) << endl;
            // guess = guess.substr(0,i) + guess.substr(i+1, guess.length());
            guess[i] = '-';
            continue;
        }


        it = secret_map.find(secret[i]);
        if (it != secret_map.end()) {
            it->second++;
        } else {
            secret_map[secret[i]] = 1;
        }
    }

    for (int j = 0; j < guess.length(); ++j) {
        it = secret_map.find(guess[j]);
        
        if (it != secret_map.end()) {
            if (it->second > 0) {
                ++cows;
                --it->second;
            }
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}