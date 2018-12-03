// Add 2 string with binaries.

#include <iostream>
#include <string>

using namespace std;


string addStrings(string a, string b);


int main(int argc, char const *argv[]) {
    char a = '0';
    char b = '0';

    cout << ((a-'0') & (b-'0')) << endl;

    return 0;
}

string addStrings(string a, string b) {
    if (a.length() == 0) return b;
    if (b.length() == 0) return a;
    
    
    // int max_length = max(a.length(), b.length());
    // int min_length = min(a.length(), b.length());

    int carry = 0;
    string sum = "";

    for (int i = a.length() - 1, j = b.length() - 1; i >= 0, j >= 0; --i, --j) {
        sum += to_string((a[i] - '0') ^ (b[i] - '0') ^ carry);
        carry = (a[i] - '0') & (b[j] - '0');
        // sum[];
    }
    return "";
}