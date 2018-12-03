#include <iostream>
#include <algorithm>

using namespace std;

int reversal(int x);

int main(int argc, char const *argv[])
{
    cout << reversal(-123) << endl;
    return 0;
}



int reversal(int x) {
        string s;
        if( x < 0) {
            s += '-';
        }
        while (x != 0) {
            s += '0' + abs(x % 10);
            x /= 10;
        }
        // s += '0' + abs(x);
        // reverse( begin(s) + (s[0] == '-'), end(s) );
        cout << s << endl;
        return stoi(s);
        
    }