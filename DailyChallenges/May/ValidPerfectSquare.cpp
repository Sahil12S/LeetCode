#include <iostream>

using namespace std;

bool isPerfectSquare(int num);

int main()
{
    int num = 4;
    cout << isPerfectSquare(num) << endl;
    return 0;
}

bool isPerfectSquare(int num)
{
    long int left = 1;
    long int right = num;

    while (left <= right)
    {
        long int mid = left + (right - left) / 2;
        if (mid * mid == num)
        {
            return true;
        }
        else if (mid * mid < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}