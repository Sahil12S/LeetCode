/**
 * Author: SAHIL SHARMA
 * Created On: 03/07/2018
 * Question: Merge 2 sorted arrays into 1 which has enough empty sapce to hold all elements of the other array.
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main() {
	int size = 6;
	int m = 3;
	int n = 3;

	vector<int> nums1(size);
	nums1[0] = 4;
	nums1[1] = 5;
	nums1[2] = 6;
	// nums1[3] = 10;
	// nums1[4] = 12;

	// vector<int> nums2 = {2, 9, 11, 14};
	vector<int> nums2 = {1, 2, 3};

	merge(nums1, m, nums2, n);

	cout << "vals: " << endl;

	for(int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << ", ";
	}
	cout << endl;

	return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0) return;
    if(m == 0) nums1 = nums2;

	vector<int>::iterator it1 = nums1.begin() + m - 1;
	vector<int>::iterator it2 = nums2.end() - 1;

	int size = nums1.size() - 1;
	cout << "size: " << size << endl;
	// bool is_inserted = false;

	// for(; m >0, n > 0;) {
	// 	if(nums1[m - 1] >= nums1[n - 1]) {
	// 		nums1[size] = nums1[m - 1];
	// 		nums1[m - 1] = 0;
	// 		// is_inserted = true;
	// 	}
	// 	else {
	// 		nums1[size] = nums2[n - 1];
	// 		n--;

			
	// 	}
	// 	size--;
	// }
	// if(n != 0) nums1[0] = nums2[0];



	while(it1 >= nums1.begin() && it2 >= nums2.begin()) {
		cout << "Here: " << *it1 << ", " << *it2 << endl;

		if(*it1 >= *it2) {
			nums1[size] = *it1;
			*it1 = 0;
			it1--;
		}
		else {
			nums1[size] = *it2;
			// *it2 = 0;
			it2--;
		}
		size--;

		
	}
	if(it2 >= nums2.begin()) {
		while(it2 >= nums2.begin()) {
			nums1[size] = *it2;
			size--;
			it2--;
		}
	}
}