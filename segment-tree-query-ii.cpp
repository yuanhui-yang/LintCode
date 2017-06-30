// Segment Tree Query II
// http://www.lintcode.com/en/problem/segment-tree-query-ii/

/*
For an array, we can build a SegmentTree for it, each node stores an extra attribute count to denote the number of elements in the the array which value is between interval start and end. (The array may not fully filled by elements)

Design a query method with three parameters root, start and end, find the number of elements in the in array's interval [start, end] by the given root of value SegmentTree.

 Notice

It is much easier to understand this problem if you finished Segment Tree Buildand Segment Tree Query first.

Have you met this question in a real interview? Yes
Example
For array [0, 2, 3], the corresponding value Segment Tree is:

                     [0, 3, count=3]
                     /             \
          [0,1,count=1]             [2,3,count=2]
          /         \               /            \
   [0,0,count=1] [1,1,count=0] [2,2,count=1], [3,3,count=1]
query(1, 1), return 0

query(1, 2), return 1

query(2, 3), return 2

query(0, 2), return 2
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root) {
            return 0;
        }
        if (start > end) {
            return 0;
        }
        if (end < root->start or start > root->end) {
            return 0;
        }
        if (start <= root->start and end >= root->end) {
            return root->count;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return query(root->left, start, end);
        }
        if (start >= mid + 1) {
            return query(root->right, start, end);
        }
        return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }
};