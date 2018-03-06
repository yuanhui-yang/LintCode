51. Previous Permutation
http://www.lintcode.com/en/problem/previous-permutation/

Given a list of integers, which denote a permutation.

Find the previous permutation in ascending order.

 Notice
The list may contains duplicate integers.

Have you met this question in a real interview? 
Example
For [1,3,2,3], the previous permutation is [1,2,3,3]

For [1,2,3,4], the previous permutation is [4,3,2,1]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        if (sz < 2) {
            return nums;
        }
        int i = sz - 1;
        while (i >= 1 and nums[i - 1] <= nums[i]) {
            --i;
        }
        if (i >= 1) {
            int j = i;
            while (j + 1 < sz and nums[i - 1] > nums[j + 1]) {
                ++j;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(next(nums.begin(), i), nums.end());
        return nums;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums, result;
    
    nums = {1, 3, 2, 3};
    result = solution.previousPermuation(nums);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    nums = {1, 2, 3, 4};
    result = solution.previousPermuation(nums);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}