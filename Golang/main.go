package main

import "fmt"

func main() {
	/*
		2 SUM (2Sum.go)

			// nums := []int{2, 7, 11, 15}
			nums := []int{0, 4, 3, 0}
			target := 0
			ans := twoSum(nums, target)
	*/
	/*
		Number is Palindrome or not (palindromeNumber.go)

			x := 123
			x := 212
			ans := isPalindrome(x)
	*/
	/*
		Longest Palindrome Substring (longestPalindromeSubstr.go)

			// s := "babad"
			s := ""
			ans := longestPalindrom(s)
	*/
	/*
		Check if a string is palindrome (validPalindrome.go)

			ans := validPalindrome("A man, a plan, a canal: Panama")
	*/
	/*
		Valid Palindrome 2 (validPalindrome2.go)

			s := "abca"
			ans := isPalindrome2(s)
	*/
	/*
		top K frequent numbers in array (topKFrequent.go)

			nums := []int{1, 1, 1, 2, 2, 3}
			k := 2
			ans := topKFrequent(nums, k)
	*/
	/*
		Search rotated sorted array (searchArray.go)

			nums := []int{4, 5, 6, 7, 0, 1, 2}
			target := 3
			ans := search(nums, target)
	*/
	/*
		Search rotated sorted array 2 (searchArray2.go)

			nums := []int{2, 5, 6, 0, 0, 1, 2}
			target := 3
			ans := search2(nums, target)
	*/
	/*
		Find duplicates in array (findDuplicates.go)

			nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
			ans := findDuplicates(nums)
	*/
	/*
		Find disappered numbers in array (findDisappeared.go)

			nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
			ans := findDisapperedNumbers(nums)
	*/
	/*
		Min size subarray sum (minSubarraySum.go)

			nums := []int{2, 3, 1, 2, 4, 3}
			s := 7
			ans := minSubArrayLen(s, nums)
	*/

	/*
		Max Subarray length with sum equal to k (maxSubarraySum.go)

			// nums := []int{1, -1, 5, -2, 3}
			// k := 3
			nums := []int{-2, -1, 2, 1}
			k := 1
			ans := maxSubArrayLen(nums, k)
	*/

	/*
		Subarray product less than k (subArrayProduct.go)

			// nums := []int{10, 5, 2, 6}
			// k := 100
			nums := []int{1, 1, 1, 1}
			k := 1
			ans := numSubarrayProductLessThanK(nums, k)
	*/
	/*
		Contiguours Array (contiguousArray.go)

			nums := []int{0, 1, 0, 0, 1, 1, 0}
			ans := findMaxLength(nums)
	*/

	/*
		Find all anagrams in a string (findAnagram.go)

			s := "cbaebabacd"
			p := "abc"
			ans := findAnagram(s, p)
	*/
	/*
		Median of two sorted arrays (medianOf2SortedArray.go)

			nums1 := []int{1, 2}
			nums2 := []int{3, 4}
			ans := findMedianSortedArrays(nums1, nums2)
	*/
	/*
		3Sum (3sum.go)
	*/
	nums := []int{-1, 0, 1, 2, -1, -4}
	ans := threeSum(nums)
	fmt.Println(ans)

}
