// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

package main

import (
	"strings"
	"unicode"
)

func validPalindrome(s string) bool {
	start := 0
	end := len(s) - 1

	s = strings.ToLower(s)

	for start < end {

		if !unicode.IsLetter(rune(s[start])) && !unicode.IsDigit(rune(s[start])) {
			start++
			continue
		}
		if !unicode.IsLetter(rune(s[end])) && !unicode.IsDigit(rune(s[end])) {
			end--
			continue
		}

		if s[start] != s[end] {
			return false
		}
		start++
		end--
	}
	return true
}
