#include <iostream>

using namespace std;

int subtractProductAndSum(int n);

int main()
{
    int n = 4421;
    cout << subtractProductAndSum(n) << endl;
    return 0;
}

int subtractProductAndSum(int n)
{
    long product = 1;
    long sum = 0;
    
    while (n > 0)
    {
        long rem = n % 10;
        product *= rem;
        sum += rem;
        n /= 10;
    }
    return int(product - sum);
}