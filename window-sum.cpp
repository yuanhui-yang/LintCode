// Window Sum
// http://www.lintcode.com/en/problem/window-sum/

/*
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], moving window size k = 3. 
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20
return [10,17,20]
*/

class Solution {
public:
	/*
	 * @param nums: a list of integers.
	 * @param k: length of window.
	 * @return: the sum of the element inside the window at each moving.
	 */
	vector<int> winSum(vector<int> &nums, int k) {
		if (nums.empty() or k <= 0 or nums.size() < k) {
			return vector<int>();
		}
		int len = nums.size(), i = 0, j = 0, sum = 0;
		vector<int> result(len - k + 1);
		for (i = 0; i < len; ++i) {
			sum += nums[i];
			if (i == k - 1) {
				result[j++] = sum;
			}
			else if (i > k - 1) {
				sum -= nums[i - k];
				result[j++] = sum;
			}
		}
		return result;
	}
};