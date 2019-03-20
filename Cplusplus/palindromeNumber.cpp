#include <iostream>

using namespace std;

bool isPalindrome(int x);

int main(int argc, char const *argv[])
{
    // int x = -123;
    int x = 121;

    cout << isPalindrome(x) << endl;
    
    return 0;
}

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int rev = 0;

    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return (x == rev || x == rev / 10);
}