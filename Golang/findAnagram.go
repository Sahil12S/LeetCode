// Given a string s and a non-empty string p,
// find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and
// the length of both strings s and p will not be larger than 20,100.

package main

func findAnagram(s string, p string) []int {
	var ans []int
	if len(s) < len(p) {
		return ans
	}
	var sArr [26]int
	var pArr [26]int

	for i := 0; i < len(p); i++ {
		sArr[s[i]-'a'] += 1
		pArr[p[i]-'a'] += 1
	}

	if sArr == pArr {
		ans = append(ans, 0)
	}

	for i := len(p); i < len(s); i++ {
		sArr[s[i]-'a'] += 1
		sArr[s[i-len(p)]-'a'] -= 1

		if sArr == pArr {
			ans = append(ans, i-len(p)+1)
		}
	}
	return ans
}
