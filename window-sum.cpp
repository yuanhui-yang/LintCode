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
		int len = nums.size(), i = 0, j = 0, sum = 0;
		if (len < k or k <= 0) {
			return {};
		}
		vector<int> result(len - k + 1, 0);
		while (i < len) {
			sum += nums[i];
			if (i == k - 1) {
				result[j] = sum;
				++j;
			}
			else if (i > k - 1) {
				sum -= nums[i - k];
				result[j] = sum;
				++j;
			}
			++i;
		}
		return result;
	}
};