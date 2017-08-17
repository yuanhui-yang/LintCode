// 463. Sort Integers
// http://www.lintcode.com/en/problem/sort-integers/

/*
Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
*/

// Selection Sort
class Solution {
public:
	
	/*
	 * @param A: an integer array
	 * @return: 
	 */
	void sortIntegers(vector<int> A) {
		// write your code here
		int sz = A.size();
		for (int i = 0; i + 1 < sz; ++i) {
			int j = i;
			for (int k = i + 1; k < sz; ++k) {
				if (A[k] < A[j]) {
					j = k;
				}
			}
			if (i < j) {
				swap(A[i], A[j]);
			}
		}
	}
};
// Selection Sort