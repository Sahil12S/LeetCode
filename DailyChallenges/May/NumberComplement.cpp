#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int findComplement(int num);

int main()
{
    int num = 1;
    cout << findComplement(num) << endl;
    return 0;
}

int findComplement(int num)
{
    vector<int> binary;
    while (num > 0)
    {
        binary.push_back(!(num % 2));
        num /= 2;
    }
    num = 0;
    int i = binary.size() - 1;
    while (i >= 0 && binary[i] == 0)
    {
        i--;
    }
    for (int j = 0; j <= i; j++)
    {
        if (binary[j])
            num += pow(2, j);
    }
    return num;
}