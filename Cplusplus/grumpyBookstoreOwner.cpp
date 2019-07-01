#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;
using VVI = std::vector<VI>;

int maxSatisfied(VI &customers, VI &grumpy, int X);

int main()
{
    VI customers = {1, 0, 1, 2, 1, 1, 7, 5};
    VI grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    std::cout << maxSatisfied(customers, grumpy, X) << '\n';
    return 0;
}

int maxSatisfied(VI &customers, VI &grumpy, int X)
{
    int maxCustomers = 0;
    int currCustomers = 0;
    FORI(0, grumpy.size())
    {
        if (grumpy[i] == 0)
        {
            currCustomers += customers[i];
        }
    }
    // std::cout << currCustomers << '\n';
    int additionalCustomers = 0;

    FORI(0, X)
    {
        if (grumpy[i] == 1)
        {
            additionalCustomers += customers[i];
        }
    }

    maxCustomers = std::max(maxCustomers, (currCustomers + additionalCustomers));
    // std::cout << additionalCustomers << '\n';

    FORI(X, grumpy.size())
    {
        if (grumpy[i - X] == 1)
        {
            additionalCustomers -= customers[i - X];
        }
        if (grumpy[i] == 1)
        {
            additionalCustomers += customers[i];
            // std::cout << i << " " << additionalCustomers << '\n';
            maxCustomers = std::max(maxCustomers, (currCustomers + additionalCustomers));
        }
    }
    return maxCustomers;
}