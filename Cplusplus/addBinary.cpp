// Add 2 binary strings

#include <iostream>

using namespace std;

string addBinary(string a, string b);

int main() {
    string ans = addBinary("11", "1");

    cout << ans << endl;

    return 0;
}

string addBinary(string a, string b) {
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    string sum = "";
    int temp;

    while (i >= 0 || j >= 0 || carry == 1) {
        carry += i >= 0 ? a[i--] - '0' : 0;
        carry += j >= 0 ? b[j--] - '0' : 0;
        sum = char(carry % 2 + '0') + sum;
        carry /= 2;
    }

    return sum;
}