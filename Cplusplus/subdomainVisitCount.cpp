// Count domain visit count

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> subdomainVists(vector<string>& cpdomains);

int main(int argc, char const *argv[])
{
    vector<string> vals = {"9001 google.com", "500 yahoo.com", "100 mail.outlook.com"};
    vector<string> ans = subdomainVists(vals);
    for (string v : ans) {
        cout << v << endl;
    }
    return 0;
}

vector<string> subdomainVists(vector<string>& cpdomains) {
    map<string, int> subdomains;
    map<string, int>::iterator it;
    vector<string> ans;

    for (string val : cpdomains) {
        size_t pos = val.find(" ");
        int length = val.length();
        int count = stoi(val.substr(0, pos));
        
        string domain = val.substr(pos + 1);

        do {
            it = subdomains.find(domain);
            if (it != subdomains.end()) {
                subdomains[domain] += count;
            } else {
                subdomains[domain] = count;
            }
            pos = domain.find(".");
            domain = domain.substr(pos + 1);
        } while (pos < length);
    }

    it = subdomains.begin();
    while (it != subdomains.end()) {
        string temp = to_string(it->second) + " " + it->first;
        ans.push_back(temp);
        ++it;
    }
    return ans;
}

string getDomain(string val, size_t pos) {
    return val.substr(pos + 1);

}