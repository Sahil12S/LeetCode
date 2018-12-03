#include <iostream>
#include <string>
#include <math.h>

using namespace std;


string licenseKeyFormatting(string S, int k);

int main(int argc, char const *argv[])
{
    char a = 'A';
    char b = 'Z';
    int x = a, y = b;
    cout << x << ',' << y << endl;
    cout << licenseKeyFormatting("a-a-a-a-", 1) << endl;
    return 0;
}

string licenseKeyFormatting(string S, int k) {
    string ans = "";
    int dashCount = 0;

    for(char c : S) {
        if (c == '-') {
            ++dashCount;
            continue;
        }
        if (c >= 97) {
            c = c - 32;
        }
        ans += c;
    }

    int pos = ans.length() % k;
    int parts = ceil(ans.length() / k);
    cout << parts << endl;
    
    while (parts > 0 && pos < ans.length()) {
        if (pos == 0) {
            pos += k;
            --parts;
            continue;
        }

        cout << "insert at " << pos << endl;
        ans.insert(pos++, "-");
        cout << "length: " << ans.length() << endl;
        --parts;
        pos += k;
        cout << "pos: " << pos << endl;
    }

    return ans;
}