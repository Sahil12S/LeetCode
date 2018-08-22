/**
 * Author: SAHIL SHARMA
 * Created On: 03/08/2018
 * Question: Check if string is palindrome or not.
 */

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(string s);


int main() {
	string s = "Hela, leh";

	if(isPalindrome(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;




	return 0;
}


bool isPalindrome(string s) {

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// cout << s << endl;

	if(s.length() <= 1) return false;

	int a = 0;
	int b = s.length() - 1;


	while(a <= b) {
		cout << int(s[a]) << endl;
		

		while(int(s[a]) < 48 ||  57 < int(s[a]) < 97 || int(s[a]) > 122) {
			a++;
			cout << a << endl;
		}
		while(int(s[b]) < 48 ||  57 < int(s[b]) < 97 || int(s[b]) > 122) {
			b--;
		}
		cout << "a: " << s[a] << ", b: " << s[b] << endl;
		if(s[a] != s[b])
			return false;
		a++;
		b--;

	}
	return true;

}