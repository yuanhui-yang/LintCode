// Sqrt(x)
// http://www.lintcode.com/en/problem/sqrtx/

/*
Implement int sqrt(int x).

Compute and return the square root of x.

Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3
*/

class Solution {
public:
	/**
	 * @param x: An integer
	 * @return: The sqrt of x
	 */
	int sqrt(long x) {
		// write your code here
		if (x <= 1) {
			return x;
		}
		long left = 1, right = x;
		while (left + 1 < right) {
			long mid = (left + right) / 2;
			if (mid * mid <= x) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		if (right * right <= x) {
			return right;
		}
		return left;
	}
};