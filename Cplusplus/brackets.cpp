/**
 * Author: SAHIL SHARMA
 * Created On: 03/07/2018
 * Question: Check if string has valid set of parenthesis.
 */

#include <iostream>
#include <stack>
#include <string>


using namespace std;


bool isValid(string s);

int main() {

	string s = "}";

	if(isValid(s)) {
		cout << "Valid" << endl;
	}
	else {
		cout << "Not valid" << endl;
	}

	return 0;
}


bool isValid(string s) {
	if(s.length() == 0 && s.length() % 2 != 0) return false;
	char c;
	stack<char> brackets;


	for(int i = 0; i < s.length(); i++) {
		c = s[i];
		

		// Method 1. Using if-else

        if((c == ')' || c == '}' || c == ']') && brackets.empty())
            return false;
        else if(c == '(' || c == '{' || c == '[')
            brackets.push(c);
        else if(c == ')' && brackets.top() == '(' || c == '}' && brackets.top() == '{' || c == ']' && brackets.top() == '[')
            brackets.pop();
        else return false;



        // Method 2. Using switch statement.
		/*switch(c) {
			case '(':
				brackets.push(c);
				break;

			case '{':
				brackets.push(c);
				break;

			case '[':
				brackets.push(c);
				break;

			case ')':
				if(brackets.empty()) return false;
				else if(brackets.top() == '(') {
					brackets.pop();
					break;
				}
				else return false;

			case '}':
				if(brackets.empty()) return false;
				else if(brackets.top() == '{') {
					brackets.pop();
					break;
				}
				else return false;

			case ']':
				if(brackets.empty()) return false;
				else if(brackets.top() == '[') {
					brackets.pop();
					break;
				}
				else return false;

			default:
				return false;
		};	*/
	}

	if(brackets.empty())
		return true;	 
	else
		return false;
}