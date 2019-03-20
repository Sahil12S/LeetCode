// Given a list of sorted characters letters containing only lowercase letters, 
// and given a target letter target, find the smallest element in the list that is larger than the given target.

#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target);

int main(int argc, char const *argv[])
{
    // vector<char> letters = {'c', 'f', 'j'};
    vector<char> letters = {'a','a','a','a','d','d','f','j'};
    vector<char> targets = {'a', 'c', 'd', 'g', 'j' , 'k'};
    // vector<char> targets = {'a', 'e'};
    
    for (char t : targets) {
        cout << t << ": " << nextGreatestLetter(letters, t) << endl; 
    }

    return 0;
}

char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size() - 1;

    if (target < letters[0] || target >= letters[letters.size() - 1]) {
        return letters[0];
    }
    int index = -1;

    // Break condition when left == right.
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] <= target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return (left + 1) < letters.size() ? letters[left + 1] : letters[0];
}