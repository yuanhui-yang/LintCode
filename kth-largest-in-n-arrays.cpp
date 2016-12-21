// 543. Kth Largest in N Arrays
// http://www.lintcode.com/en/problem/kth-largest-in-n-arrays/
// Find K-th largest element in N arrays.
// Notice
// You can swap elements in the array
// Example
// In n=2 arrays [[9,3,2,4,7],[1,2,3,4,8]], the 3rd largest element is 7.
// In n=2 arrays [[9,3,2,4,8],[1,2,3,4,2]], the 1st largest element is 9, 2nd largest element is 8 and etc.
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
class Solution {
public:
	/**
	* @param arrays a list of array
	* @param k an integer
	* @return an integer, K-th largest element in N arrays
	*/
	int KthInArrays(vector<vector<int>>& arrays, int k) {
	// Write your code here
		const int arrays_size = arrays.size();
		if (arrays_size == 0) return 0;
		if (arrays_size == 1) {
			nth_element(begin(arrays.front()), next(begin(arrays.front()), arrays.front().size() - k), end(arrays.front()));
			return arrays.front()[arrays.front().size() - k];
		}
		priority_queue<pair<int, int>> max_heap;
		for (auto &i : arrays) sort(begin(i), end(i), greater<int>());
		for (int i = 0; i < arrays_size; i++) {
			if (!arrays[i].empty()) {
				max_heap.push(make_pair(arrays[i].front(), i));
			}
		}
		vector<int> indexs(arrays_size, 0);
		int result = 0;
		for (int i = 0; i < k; i++) {
			pair<int, int> max_heap_top = max_heap.top();
			max_heap.pop();
			result = max_heap_top.first;
			int arrays_index = max_heap_top.second;
			if (indexs[arrays_index] + 1 < (int)arrays[arrays_index].size()) {
				max_heap.push(make_pair(arrays[arrays_index][++indexs[arrays_index]], arrays_index));
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> arrays;
	arrays = {{9, 3, 2, 4, 7}, {1, 2, 3, 4, 8}};
	assert(7 == solution.KthInArrays(arrays, 3));
	arrays = {{9, 3, 2, 4, 8}, {1, 2, 3, 4, 2}};
	assert(9 == solution.KthInArrays(arrays, 1));
	assert(8 == solution.KthInArrays(arrays, 2));
	arrays = {{1, 7, 5, 10, 2}};
	assert(2 == solution.KthInArrays(arrays, 4));
	cout << "\nPassed All\n";
	return 0;
}