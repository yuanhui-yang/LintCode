// Sort Integers
// http://www.lintcode.com/en/problem/sort-integers/

/*
Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

Have you met this question in a real interview? Yes
Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
*/

// BEGIN: Bubble Sort
class Solution {
public:
	
	/*
	 * @param A: an integer array
	 * @return: 
	 */
	void sortIntegers(vector<int> & A) {
		// write your code here
		int len = A.size(), i, j, temp;
		for (i = 0; i <= len - 2; ++i) {
			for (j = 0; j <= len - 2 - i; ++j) {
				if (A[j] > A[j + 1]) {
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
	}
};
// END: Bubble Sort

// BEGIN: Selection Sort
class Solution {
public:
	/*
	 * @param A: an integer array
	 * @return: 
	 */
	void sortIntegers(vector<int> &A) {
		// write your code here
		int len = A.size(), i, j, temp, min, location;
		for (i = 0; i <= len - 1; ++i) {
			min = A[i];
			location = i;
			for (j = i + 1; j <= len - 1; ++j) {
				if (A[j] < min) {
					min = A[j];
					location = j;
				}
			}
			if (location != i) {
				temp = A[i];
				A[i] = min;
				A[location] = temp;
			}
		}
	}
};
// END: Selection Sort
