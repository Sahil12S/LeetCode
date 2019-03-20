// Add 2 integers represented as strings
#include <iostream>
#include <string>

using namespace std;

string addString(string num1, string num2);

int main(int argc, char const *argv[])
{
    cout << addString("586", "1254") << endl;
    return 0;
}

string addString(string num1, string num2) {
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;
    string sum = "";

    while (i >= 0 || j >= 0 || carry) {
        carry += i >= 0 ? num1[i--] - '0' : 0; 
        carry += j >= 0 ? num2[j--] - '0' : 0;
        cout << "carry " << carry << endl;
        sum = to_string(carry % 10) + sum;
        carry /= 10;
    }
    return sum;
}