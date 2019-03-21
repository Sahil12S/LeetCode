/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
*/

package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)

	if m > n {
		nums1, nums2, m, n = nums2, nums1, n, m
	}

	low := 0
	high := m

	var i, j int

	for low <= high {
		i = (low + high) / 2
		j = (m+n+1)/2 - i

		if i < m && nums2[j-1] > nums1[i] {
			low = i + 1
		} else if i > 0 && nums2[j] < nums1[i-1] {
			high = i - 1
		} else {
			maxLeft := 0.0
			if i == 0 {
				maxLeft = float64(nums2[j-1])
			} else if j == 0 {
				maxLeft = float64(nums1[i-1])
			} else {
				maxLeft = float64(max(nums1[i-1], nums2[j-1]))
			}

			if (m+n)%2 == 1 {
				return maxLeft
			}

			minRight := 0.0
			if i == m {
				minRight = float64(nums2[j])
			} else if j == n {
				minRight = float64(nums1[i])

			} else {
				minRight = float64(min(nums1[i], nums2[j]))
			}
			return (maxLeft + minRight) / 2.0
		}
	}
	return 0.0
}
