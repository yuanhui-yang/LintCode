// Longest Palindrome
// http://www.lintcode.com/en/problem/longest-palindrome/

/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

 Notice

Assume the length of given string will not exceed 1010.

Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

public class Solution {
	/*
	 * @param s: a string which consists of lowercase or uppercase letters
	 * @return: the length of the longest palindromes that can be built
	 */
	public int longestPalindrome(String s) {
		// write your code here
		Set<Character> hashSet = new HashSet<Character>();
		for (char ch : s.toCharArray()) {
			if (hashSet.contains(ch)) {
				hashSet.remove(ch);
			}
			else {
				hashSet.add(ch);
			}
		}
		return hashSet.isEmpty() ? s.length() : s.length() - hashSet.size() + 1;
	}
}