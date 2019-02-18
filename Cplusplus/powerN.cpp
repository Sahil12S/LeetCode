// Calculate x power N

#include <iostream>

using namespace std;

double myPow(double x, int n);
double power(double x, int n);

int main(int argc, char const *argv[])
{
    cout << myPow(2.00000, 10) << endl;
    return 0;
}

double myPow(double x, int n)
{
    long long N = n;

    if (n < 0)
    {
        x = 1 / x;
        N = -N;
    }

    return power(x, N);
}

double power(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }

    double half = power(x, n/2);

    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return half * half * x;
    }
}