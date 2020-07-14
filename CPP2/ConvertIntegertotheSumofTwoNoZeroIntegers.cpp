#include <iostream>
#include <vector>

using namespace std;

vector<int> getNoZeroIntegers(int n);
bool hasZero(int num);

int main()
{
    int n = 1010;
    vector<int> ans = getNoZeroIntegers(n);
    cout << ans[0] << ", " << ans[1] << '\n';
    return 0;
}

vector<int> getNoZeroIntegers(int n)
{
    int left = 1, right = n - 1;
    while (left < right)
    {
        if (!hasZero(left) && !hasZero(right))
        {
            break;
        }

        left++;
        right--;
    }
    return {left, right};
}

bool hasZero(int num)
{
    while (num > 0)
    {
        if (num % 10 == 0)
        {
            return true;
        }
        num /= 10;
    }
    return false;
}