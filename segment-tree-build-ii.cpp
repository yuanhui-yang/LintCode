// Segment Tree Build II
// http://www.lintcode.com/en/problem/segment-tree-build-ii/

/*
The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:

The root's start and end is given by build method.
The left child of node A has start=A.left, end=(A.left + A.right) / 2.
The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
if start equals to end, there will be no children for this node.
Implement a build method with a given array, so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, return the root of this segment tree.

Have you met this question in a real interview? Yes
Clarification
Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:

which of these intervals contain a given point
which of these points are in a given interval
See wiki:
Segment Tree
Interval Tree

Example
Given [3,2,1,4]. The segment tree will be:

                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int n = A.size();
        SegmentTreeNode * root = f(0, n - 1);
        for (int i = 0;  i < n; ++i) {
            g(root, i, A[i]);
        }
        return root;
    }
    SegmentTreeNode * f(int start, int end) {
        if (start > end) {
            return NULL;
        }
        SegmentTreeNode * node = new SegmentTreeNode(start, end, INT_MIN);
        if (start == end) {
            return node;
        }
        int mid = start + (end - start) / 2;
        node->left = f(start, mid);
        node->right = f(mid + 1, end);
        return node;
    }
    void g(SegmentTreeNode * root, int index, int val) {
        if (!root) {
            return;
        }
        if (index < root->start or index > root->end) {
            return;
        }
        root->max = max(root->max, val);
        if (index == root->start and index == root->end) {
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (index <= mid) {
            g(root->left, index, val);
        }
        else {
            g(root->right, index, val);
        }
    }
};