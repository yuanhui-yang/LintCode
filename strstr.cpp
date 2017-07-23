// strStr
// http://www.lintcode.com/en/problem/strstr/

/*
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.
*/

class Solution {
public:
	/**
	 * Returns a index to the first occurrence of target in source,
	 * or -1  if target is not part of source.
	 * @param source string to be scanned.
	 * @param target string containing the sequence of characters to match.
	 */
	int strStr(const char *source, const char *target) {
		if (!source or !target) {
			return -1;
		}
		// write your code here
		int M = strlen(source), N = strlen(target), i = 0, j = -1;
		if (N == 0) {
			return 0;
		}
		vector<int> A(N + 1);
		A[0] = -1;
		while (i < N) {
			if (j == -1 or target[i] == target[j]) {
				A[++i] = ++j;
			}
			else {
				j = A[j];
			}
		}
		i = 0;
		j = 0;
		while (i < M) {
			if (j == -1 or source[i] == target[j]) {
				++i;
				++j;
			}
			else {
				j = A[j];
			}
			if (j == N) {
				return i - N;
			}
		}
		return -1;
	}
};
