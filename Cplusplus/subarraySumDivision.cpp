/**
 * Given an array A of integers,
 * return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VI = std::vector<int>;

int subarraysDivByK(VI &A, int K);

int main()
{
    VI A = {4, 5, 0, -2, -3, 1};
    int K = 5;
    std::cout << subarraysDivByK(A, K) << '\n';
    return 0;
}

int subarraysDivByK(VI &A, int K)
{
    // std::unordered_map<int, int> mp;
    // mp[0] = 1;

    // Store remainder in array
    VI mp(K, 0);
    mp[0] = 1;

    int sum = 0;
    int count = 0;

    FORI(0, A.size())
    {
        sum = (sum + A[i]) % K;
        if (sum < 0)
        {
            sum += K;
        }
        // Check if we have encountered that remainder before
        count += mp[sum];
        mp[sum] += 1;
    }
    return count;
}