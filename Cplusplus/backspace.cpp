// Check if 2 strings are same if # represents a backspace character.
#include <iostream>
#include <vector>

using namespace std;

bool backspaceCompare(string S, string T);

int main(int argc, char const *argv[])
{
    vector<string> casesS = {"ab#c", "ab##", "a##c", "a#c", "gtc#uz#", "bxj##tw", "bbbextm"};
    vector<string> casesT = {"ad#c", "c#d#", "#a#c", "b", "gtcm##uz#", "bxo#j##tw", "bbb#extm"};

    for (int i = 0; i < casesS.size(); ++i) {
        cout << backspaceCompare(casesS[i], casesT[i]) << endl;

    }

    return 0;
}

bool backspaceCompare(string S, string T) {
    int skipS = 0, skipT = 0;
    int i = S.length() - 1, j = T.length() - 1;


    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                ++skipS, --i;
            } else if (skipS > 0) {
                --skipS, --i;
            } else break;
        }

        while (j >= 0) {
            if (T[j] == '#') {
                ++skipT, --j;
            } else if (skipT > 0) {
                --skipT, --j;
            } else break;
        }

        if (i >= 0 && j>= 0 && S[i] != T[j]) {
            return false;
        }
        if ( (i >= 0) != (j >= 0) ) {
            return false;
        }
        --i, --j;
    }
    return true;
}