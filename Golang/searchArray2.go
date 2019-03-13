/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.
*/
package main

import "math"

func search2(nums []int, target int) bool {
	maxInt := math.MaxInt32
	minInt := math.MinInt32

	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2

		var n int

		if (left != right) && (nums[left] == nums[right]) {
			right--
			continue
		}

		if (nums[mid] < nums[0]) == (target < nums[0]) {
			n = nums[mid]
		} else {
			if target < nums[0] {
				n = minInt
			} else {
				n = maxInt
			}
		}

		if n < target {
			left = mid + 1
		} else if n > target {
			right = mid - 1
		} else {
			return true
		}
	}
	return false
}
