#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address);

int main()
{
    string address = "255.100.50.0";
    cout << defangIPaddr(address) << endl;
    return 0;
}

string defangIPaddr(string address)
{
    string ans = "";
    for (char c : address)
    {
        if (c != '.')
        {
            ans += c;
        }
        else
        {
            ans += "[.]";
        }
    }
    return ans;
}