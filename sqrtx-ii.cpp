// Sqrt(x) II
// http://www.lintcode.com/en/problem/sqrtx-ii/

/*
Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.

 Notice

You do not care about the accuracy of the result, we will help you to output results.

Example
Given n = 2 return 1.41421356
*/

class Solution {
public:
	/**
	 * @param x a double
	 * @return the square root of x
	 */
	double sqrt(double x) {
		// Write your code here
		double left = 0, right = max(1.0, x);
		while (right - left >= 1e-12) {
			double mid = (left + right) / 2;
			if (mid * mid <= x) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
};