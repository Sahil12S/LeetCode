/**
 * Author: SAHIL SHARMA
 * Created On: March 4, 2018
 * Question: The count-and-say sequence is the sequence of integers with the first five terms as following:

 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string
 */



#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n);

int main() {
	int num = 10;
	string s = countAndSay(num);

	cout << s << endl;

	return 0;
}


string countAndSay(int n) {
	string ans = "1";
	int count = 0;
	char prev = ' ';
	string num;

	while(n > 1) {
		num = ans;
		ans = "";
		prev = num[0];

		for(int i = 0; i < num.length(); i++) {
			if(num[i] == prev) {
				count++;
			}
			else {
				ans += to_string(count) + prev;
				prev = num[i];
				count = 1;
			}

		}
		ans = ans + to_string(count) + num[num.length() - 1];
		count = 0;
		n--;
	}
	
	return ans;
}
