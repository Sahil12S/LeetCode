#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n);
int climb (int i, int n);
int climb2 (int i, int n, vector<int> steps);

int main(int argc, char const *argv[])
{
    cout << climbStairs(4) << endl;
    return 0;
}

int climbStairs(int n)
{
    // vector<int> steps(n + 1, 0);
    //return climb(0, n);
    // return climb2(0, n, steps);

    if (n == 1)
    {
        return 1;
    }

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++)
    {
        int third = first + second;
        first = second;
        second = third;
    }

    return second;

}

int climb (int i, int n)
{
    if (i > n)
    {
        return 0;
    }
    else if (i == n)
    {
        return 1;
    }

    return climb(i + 1, n) + climb(i + 2, n);
}

int climb2(int i, int n, vector<int> steps)
{
    if (i > n)
    {
        return 0;
    }
    else if (i == n)
    {
        return 1;
    }

    if (steps[i] > 0)
    {
        return steps[i];
    }

    steps[i] = climb2(i + 1, n, steps) + climb2(i + 2, n, steps);

    return steps[i];
}