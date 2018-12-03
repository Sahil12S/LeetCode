#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t);

int main(int argc, char const *argv[])
{
    string s = "paper";
    string t = "title";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}

bool isIsomorphic(string s, string t) {
    map<char, char> map_st;
    map<char, char> map_ts;
    map<char, char>::iterator st_iter;
    map<char, char>::iterator ts_iter;

    for (int i = 0; i < s.length(); ++i) {
        st_iter = map_st.find(s[i]);
        ts_iter = map_ts.find(t[i]);

        if (st_iter != map_st.end() && ts_iter != map_ts.end()) {
            if (st_iter->second != t[i] || ts_iter->second != s[i]) {
                return false;
            }
        } else if (st_iter != map_st.end() || ts_iter != map_ts.end()) {
            return false;
        } else {
            map_st[s[i]] = t[i];
            map_ts[t[i]] = s[i];
            cout << "mapping S: " << s[i] << " to " << t[i] << " & ";
            cout << "mapping T: " << t[i] << " to " << s[i] << endl;
        }
    }
    return true;
}