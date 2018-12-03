// Given a positive integer num, write a function which returns True if num is a perfect square else False.

#include <iostream>

using namespace std;

bool isPerfectSquare(int num);

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 20; ++i) {
        if (isPerfectSquare(i)){
            cout << "Perfect: " << i << endl;
        } else {
            cout << "Not one: " << i << endl;
        }
    }
    // cout << isPerfectSquare(5) << endl;
    return 0;
}

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false;
    }
    int left = 1, right = num;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if ((mid * mid) == num) {
            return mid;
        }
        if ((num / mid) < mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (left*left == num) {
        return true;
    }
    return false;
}