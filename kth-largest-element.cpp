// 5. Kth Largest Element
// http://www.lintcode.com/en/problem/kth-largest-element/
// Find K-th largest element in an array.
// Notice
// You can swap elements in the array
// Example
// In array [9,3,2,4,8], the 3rd largest element is 4.
// In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	/*
	* param k : description of k
	* param nums : description of array and index 0 ~ n-1
	* return: description of return
	*/
	int kthLargestElement(int k, vector<int> nums) {
	// write your code here
		const int nums_size = nums.size();
		nth_element(begin(nums), next(begin(nums), nums_size - k), end(nums));
		return nums[nums_size - k];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {9, 3, 2, 4, 8};
	assert(4 == solution.kthLargestElement(3, nums));
	nums = {1, 2, 3, 4, 5};
	assert(5 == solution.kthLargestElement(1, nums));
	cout << "\nPassed All\n";
	return 0;
}