// 443. Two Sum II
// http://www.lintcode.com/en/problem/two-sum-ii/
// Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.
// Example
// Given numbers = [2, 7, 11, 15], target = 24. Return 1. (11 + 15 is the only pair)
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	/**
	* @param nums: an array of integer
	* @param target: an integer
	* @return: an integer
	*/
	int twoSum2(vector<int> &nums, int target) {
	// Write your code here
		const int nums_size = nums.size();
		if (nums_size < 2) return 0;
		sort(begin(nums), end(nums));
		int left = 0;
		int right = nums_size - 1;
		int result = 0;
		while (left < right) {
			if (nums[left] + nums[right] > target) {
				result += right-- - left;
			}
			else {
				left++;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {2, 7, 11, 15};
	assert(1 == solution.twoSum2(nums, 24));
	cout << "\nPassed All\n";
	return 0;
}