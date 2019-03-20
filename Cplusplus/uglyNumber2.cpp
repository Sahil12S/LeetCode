// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
// Given a number n, the task is to find n’th Ugly number.

#include <iostream>
#include <vector>

using namespace std;

int getUglyNum (int n);
// int getMin(int a, int b, int c);

int main(int argc, char const *argv[])
{
    cout << getUglyNum(150) << endl;
    return 0;
}

int getUglyNum (int n)
{
    vector<int> nums(n);
    nums[0] = 1;

    int i2, i3, i5;
    i2 = i3 = i5 = 0;

    unsigned int next_multiple_2 = 2;
    unsigned int next_multiple_3 = 3;
    unsigned int next_multiple_5 = 5;
    unsigned int next_ugly_num = 1;

    for (int i = 1; i < n; i++)
    {
        next_ugly_num = min( min(next_multiple_2, next_multiple_3), next_multiple_5);
        nums[i] = next_ugly_num;

        if (next_ugly_num == next_multiple_2)
        {
            i2++;
            next_multiple_2 = nums[i2] * 2;
        }

        if (next_ugly_num == next_multiple_3)
        {
            i3++;
            next_multiple_3 = nums[i3] * 3;
        }

        if (next_ugly_num == next_multiple_5)
        {
            i5++;
            next_multiple_5 = nums[i5] * 5;
        }
    }
    return next_ugly_num;
}

// int getMin(unsigned int a, unsigned int b, unsigned int c) {
//     unsigned int 
// }