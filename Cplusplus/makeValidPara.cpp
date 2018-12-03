#include <iostream>
#include <stack>

using namespace std;

string makeValid(string para);

int main(int argc, char const *argv[])
{
    cout << makeValid("()()))(()") << endl;
    return 0;
}

string makeValid(string str) {
    string to_front = "";
    string to_back = "";

    int check = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            check += 1;
        } else if (str[i] == ')') {
            check -= 1;
        }

        if (check < 0) {
            to_front += "(";
            check++;
        } 
    }
    for( int i = 0 ;i < check ; ++i){
        to_back += ")";
    }

    return to_front + str + to_back;
}