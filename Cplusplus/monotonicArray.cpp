// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

#include <iostream>
#include <vector>

using namespace std;

bool isMonotone(vector<int>& A);
 
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2,3};
    // vector<int> nums = {1,3,2};
    
    if(isMonotone(nums))
    {
        cout << "Monotone" << endl;
    }
    else
    {
        cout << "Not Monotone" << endl;
    }
    

    return 0;
}

bool isMonotone(vector<int>& A)
{
    bool isDecreasing = true, isIncreasing = true;

    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] < A[i + 1])
        {
            isIncreasing = false;
        }
        if (A[i] > A[i + 1])
        {
            isDecreasing = false;
        }
    }

    return isDecreasing || isIncreasing;
}