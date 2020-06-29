#include <iostream>

using namespace std;

int numberOfSteps (int num);

int main()
{
    int num = 8;
    cout << numberOfSteps(num) << endl;
    return 0;
}

int numberOfSteps (int num)
{
    int count = 0;

    while (num > 0)
    {
        count++;
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num--;
        }
    }
    return count;
}
