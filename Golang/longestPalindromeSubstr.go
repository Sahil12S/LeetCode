// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

package main

func longestPalindrom(s string) string {
	start := 0
	end := 0

	for i := 0; i < len(s); i++ {
		l1 := expandAroundCenter(s, i, i)
		l2 := expandAroundCenter(s, i, i+1)

		len := Max(l1, l2)

		if len > (end - start) {
			start = i - (len-1)/2
			end = i + len/2
		}
	}
	return s[start:(end + 1)]
}

func expandAroundCenter(s string, left, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return right - left - 1
}

// Max return maximum of 2 integer values
func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
