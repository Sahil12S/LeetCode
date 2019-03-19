/**
 * Author: SAHIL SHARMA
 * Created On: 03/07/2018
 * Question: Find longest common prefix from the array of string.
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;


string longestCommonPrefix1(vector<string>& strs);
string longestCommonPrefix2(vector<string>& strs);


int main() {
	vector<string> s = {"sahilsharma", "sahilshar", "sahil", "sahils", "sah", "sa"};
	vector<string> s2 = {"s"};

	string ans = longestCommonPrefix2(s2);

	cout << "Longest common prefix: " << ans << endl;

	return 0;
}


string longestCommonPrefix1(vector<string>& strs) {
	string ans = "";

	if(strs.size() == 0) return ans;
	else if(strs.size() == 1) return strs[0];
	else ans = strs[0];

	string temp;
	string str;

	for(int i = 0; i < strs.size(); i++) {
		if(strs[i].length() >= temp.length()) {
			str = ans;
			temp = strs[i];
		}
		else {
			str = strs[i];
			temp = ans;
		}
		ans = "";
		size_t n = 0;
		
		for(int j = 0; j < str.length(); j++) {
			if(str[j] == temp[j])
				ans += str[j];
			else
				break;
		}
		
	}
	return ans;

}

string longestCommonPrefix2(vector<string>& strs) {
	string ans = "";

	if(strs.size() == 0) return ans;
	else if(strs.size() == 1) return strs[0];
	else ans = strs[0];

	string temp;
	string str;


	for(int i = 0; i < strs.size(); i++) {
		if(strs[i].length() <= ans.length()) {
			ans = strs[i];
		}
	}

	int size = ans.length();

	for(int i = 0; i < strs.size(); i++) {
		if(strs[i].substr(0, size) != ans) {
			while(strs[i].substr(0, size) != ans) {
				ans = ans.substr(0, size-1);
				size = ans.length();
				if(ans == "") return "";
			}
		}
	}	
}