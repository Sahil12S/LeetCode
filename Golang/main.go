package main

import "fmt"

func main() {
	/*
		2 SUM (2Sum.go)

			// nums := []int{2, 7, 11, 15}
			nums := []int{0, 4, 3, 0}
			target := 0
			ans := twoSum(nums, target)
			fmt.Println(ans)
	*/
	/*
		Number is Palindrome or not (palindromeNumber.go)

			x := 123
			x := 212
			fmt.Println(isPalindrome(x))
	*/
	/*
		Longest Palindrome Substring (longestPalindromeSubstr.go)

			// s := "babad"
			s := ""
			fmt.Println(longestPalindrom(s))
	*/
	/*
		Check if a string is palindrome (validPalindrome.go)

			a := validPalindrome("A man, a plan, a canal: Panama")
			fmt.Println(a)
	*/
	/*
		Valid Palindrome 2 (validPalindrome2.go)

			s := "abca"
			fmt.Println(isPalindrome2(s))
	*/
	/*
		top K frequent numbers in array (topKFrequent.go)

			nums := []int{1, 1, 1, 2, 2, 3}
			k := 2

			ans := topKFrequent(nums, k)
			fmt.Println(ans)
	*/
	/*
		Search rotated sorted array (searchArray.go)

			nums := []int{4, 5, 6, 7, 0, 1, 2}
			target := 3
			ans := search(nums, target)
			fmt.Println(ans)
	*/
	/*
		Search rotated sorted array 2 (searchArray2.go)

			nums := []int{2, 5, 6, 0, 0, 1, 2}
			target := 3
			ans := search2(nums, target)
			fmt.Println(ans)
	*/
	/*
		Find duplicates in array (findDuplicates.go)

			nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
			ans := findDuplicates(nums)
			fmt.Println(ans)
	*/
	/*
		Find disappered numbers in array (findDisappeared.go)
	*/
	nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
	ans := findDisapperedNumbers(nums)
	fmt.Println(ans)

}
