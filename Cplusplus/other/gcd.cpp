// Find greatest common divisor of 2 given numbers

#include <iostream>

using namespace std;

int gcdRecursion(int num1, int num2);
int gcdIteration(int num1, int num2);

int main(int argc, char const *argv[])
{
    
    cout << gcdRecursion(156, 36) << endl;
    cout << gcdIteration(156, 36) << endl;
    return 0;
}

int gcdRecursion(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcdRecursion(num2, num1 % num2);
    }
    
}

int gcdIteration(int num1, int num2)
{
    while (num2 != 0)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    return num1;
}