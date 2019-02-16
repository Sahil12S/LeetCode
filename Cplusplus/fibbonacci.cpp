// Implement Fibbonacci using recursion

#include <iostream>

using namespace std;

int fib (int N);

int main(int argc, char const *argv[])
{
    cout << fib(5) << endl;
    return 0;
}

int fib (int N)
{
    if (N < 2)
    {
        return N;
    }

    int a = 0, b = 1, c;
    int i = 2;
    
    while (i++ < N)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}