/*
Your are given an array of positive integers nums.
Count and print the number of (contiguous) subarrays
where the product of all the elements in the subarray is less than k.
*/

package main

import "fmt"

func numSubarrayProductLessThanK(nums []int, k int) int {
	if k <= 1 {
		return 0
	}

	left := 0
	product := 1
	length := 0

	for right := 0; right < len(nums); right++ {
		product *= nums[right]

		for product >= k {
			product /= nums[left]
			left++
			fmt.Println(left)
		}
		length += (right - left + 1)
	}
	return length
}
