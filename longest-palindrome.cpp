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

class Solution {
public:
	/*
	 * @param s: a string which consists of lowercase or uppercase letters
	 * @return: the length of the longest palindromes that can be built
	 */
	int longestPalindrome(string s) {
		// write your code here
		unordered_set<char> hashset;
		for (const auto & ch : s) {
			if (hashset.count(ch)) {
				hashset.erase(ch);
			}
			else {
				hashset.insert(ch);
			}
		}
		return hashset.empty() ? s.size() : s.size() - hashset.size() + 1;
	}
};