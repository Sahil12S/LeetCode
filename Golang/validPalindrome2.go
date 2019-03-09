// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

package main

func isPalindrome2(s string) bool {
	i := 0
	j := len(s) - 1

	for i < j {
		if s[i] != s[j] {
			return checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j)
		}
		i++
		j--
	}
	return true
}

func checkPalindrome(s string, i, j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}
