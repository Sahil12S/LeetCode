// In a list of songs, the i-th song has a duration of time[i] seconds. 
// Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
// Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.

#include <iostream>
#include <vector>
// #include "../../logger.cpp"

using namespace std;

int numPairsDivisibleBy60(vector<int>& time);

void printVector(vector<int> vec);
#include "../../logger.cpp"

int main(int argc, char const *argv[])
{
    // vector<int> time = {30, 20, 150, 100, 40};
    vector<int> time = {60,60,60};
    cout << "Num of pairs: " << numPairsDivisibleBy60(time) << endl;
    return 0;
}

int numPairsDivisibleBy60(vector<int>& time)
{
    vector<int> sixty(60, 0);

    for (int i = 0; i < time.size(); i++)
    {
        sixty[time[i] % 60]++;
    }
    int sum = 0;
    for (int i = 1, j = 59; i < 30; i++, j--)
    {
        sum += sixty[i] * sixty[j];
    }

    // Condition when modulo gives 30
    sum += (sixty[30] * (sixty[30] - 1)) / 2;

    // Condidtion when modulus give 0
    sum += (sixty[0] * (sixty[0] - 1)) / 2;
    return sum;
}