// Interval Sum II
// http://www.lintcode.com/en/problem/interval-sum-ii/

/*
Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):

For query(start, end), return the sum from index start to index end in the given array.
For modify(index, value), modify the number in the given index to value
 Notice

We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Have you met this question in a real interview? Yes
Example
Given array A = [1,2,7,8,5].

query(0, 2), return 10.
modify(0, 4), change A[0] from 1 to 4.
query(0, 1), return 6.
modify(2, 1), change A[2] from 7 to 1.
query(2, 4), return 14.
*/

class Solution {
public:
    /* you may need to use some attributes here */
    

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        if (A.empty()) {
            return;
        }
        int n = A.size();
        tree = new Tree(0, n - 1);
        for (int i = 0; i < n; ++i) {
            tree->insert(i, A[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return tree->query(start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        tree->modify(index, value);
    }
private:
    struct Node {
        int begin, end;
        long long val;
        Node * left, * right;
        Node(int begin, int end) {
            this->begin = begin;
            this->end = end;
            this->val = 0;
            this->left = NULL;
            this->right = NULL;
        }
    };
    struct Tree {
        Node * root;
        Tree(int begin, int end) {
            this->root = f(begin, end);
        }
        Node * f(int begin, int end) {
            if (begin > end) {
                return NULL;
            }
            Node * node = new Node(begin, end);
            if (begin == end) {
                return node;
            }
            int mid = begin + (end - begin) / 2;
            node->left = f(begin, mid);
            node->right = f(mid + 1, end);
            return node;
        }
        void insert(int index, int val) {
            g(root, index, val);
        }
        void g(Node * node, int index, int val) {
            if (!node) {
                return;
            }
            if (index < node->begin or index > node->end) {
                return;
            }
            node->val += val;
            int mid = node->begin + (node->end - node->begin) / 2;
            if (index <= mid) {
                g(node->left, index, val);
            }
            else {
                g(node->right, index, val);
            }
        }
        int query(int begin, int end) {
            return h(root, begin, end);
        }
        long long h(Node * node, int begin, int end) {
            if (!node) {
                return 0;
            }
            if (begin > end) {
                return 0;
            }
            if (begin <= node->begin and node->end <= end) {
                return node->val;
            }
            int mid = node->begin + (node->end - node->begin) / 2;
            if (end <= mid) {
                return h(node->left, begin, end);
            }
            if (mid + 1 <= begin) {
                return h(node->right, begin, end);
            }
            return h(node->left, begin, mid) + h(node->right, mid + 1, end);
        }
        void modify(int index, int val) {
            i(root, index, val - query(index, index));
        }
        void i(Node * node, int index, int val) {
            if (!node) {
                return;
            }
            if (index < node->begin or node->end < index) {
                return;
            }
            node->val += val;
            int mid = node->begin + (node->end - node->begin) / 2;
            if (index <= mid) {
                i(node->left, index, val);
            }
            else {
                i(node->right, index, val);
            }
        }
    };
    Tree * tree;
};
