// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

#include <iostream>
#include <vector>


using namespace std;

void merge( vector<int>& nums1, int m, vector<int>& nums2, int n );
#include "logger.cpp"

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {4, 5, 6};
    int m = 3, n = 3;
    merge( nums1, m, nums2, n );

    printVector( nums1 );

    return 0;
}

void merge( vector<int>& nums1, int m, vector<int>& nums2, int n )
{
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while ( p1 >= 0 && p2 >= 0 )
    {
        nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    }

    while ( p2 >= 0 )
    {
        nums1[p--] = nums2[p2--];
    }
}