/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
*/

package main

import "math"

func search(nums []int, target int) int {
	maxInt := math.MaxInt32
	minInt := math.MinInt32

	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2

		var n int
		if (nums[mid] < nums[0]) == (target < nums[0]) {
			n = nums[mid]
		} else {
			if target < nums[0] {
				n = minInt
			} else {
				n = maxInt
			}
		}

		if target < n {
			right = mid - 1
		} else if target > n {
			left = mid + 1
		} else {
			return mid
		}
	}
	return -1
}
