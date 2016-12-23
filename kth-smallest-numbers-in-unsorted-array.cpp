// 461. Kth Smallest Numbers in Unsorted Array
// http://www.lintcode.com/en/problem/kth-smallest-numbers-in-unsorted-array/
// Find the kth smallest numbers in an unsorted integer array.
// Example
// Given [3, 4, 1, 2, 5], k = 3, the 3rd smallest number is 3.
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	/*
	* @param k an integer
	* @param nums an integer array
	* @return kth smallest element
	*/
	int kthSmallest(int k, vector<int> nums) {
	// write your code here
		const int nums_size = nums.size();
		nth_element(begin(nums), next(begin(nums), k - 1), end(nums));
		return nums[k - 1];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {3, 4, 1, 2, 5};
	assert(3 == solution.kthSmallest(3, nums));
	cout << "\nPassed All\n";
	return 0;
}