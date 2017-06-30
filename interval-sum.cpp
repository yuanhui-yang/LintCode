// Interval Sum
// http://www.lintcode.com/en/problem/interval-sum/

/*
Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.

 Notice

We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        if (A.empty() or queries.empty()) {
            return {};
        }
        int n = A.size();
        Tree tree(0, n - 1);
        for (int i = 0; i < n; ++i) {
            tree.insert(i, A[i]);
        }
        vector<long long> result;
        for (const auto &i : queries) {
            result.push_back(tree.query(i.start, i.end));
        }
        return result;
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
            g(node->left, index, val);
            g(node->right, index, val);
        }
        long long query(int begin, int end) {
            return h(root, begin, end);
        }
        long long h(Node * node, int begin, int end) {
            if (!node) {
                return 0;
            }
            if (begin > end) {
                return 0;
            }
            if (end < node->begin or node->end < begin) {
                return 0;
            }
            if (begin <= node->begin and node->end <= end) {
                return node->val;
            }
            int mid = node->begin + (node->end - node->begin) / 2;
            if (end <= mid) {
                return h(node->left, begin, end);
            }
            if (begin >= mid + 1) {
                return h(node->right, begin, end);    
            }
            return h(node->left, begin, mid) + h(node->right, mid + 1, end);
        }
    };
};