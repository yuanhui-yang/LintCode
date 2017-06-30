// Count of Smaller Number
// http://www.lintcode.com/en/problem/count-of-smaller-number/

/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller than the given integer.

 Notice

We suggest you finish problem Segment Tree Build and Segment Tree Query II first.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        Tree tree(0, 10000);
        for (const auto &i : A) {
            tree.insert(i);
        }
        vector<int> result;
        for (const auto &i : queries) {
            result.push_back(tree.query(0, i - 1));
        }
        return result;
    }
private:
    struct Node {
        int a, b, c;
        Node * left, * right;
        Node(int begin, int end) {
            a = begin;
            b = end;
            c = 0;
            left = NULL;
            right = NULL;
        }
    };
    struct Tree {
        Node * root;
        Tree(int begin, int end) {
            root = f1(begin, end);
        }
        Node * f1(int begin, int end) {
            if (begin > end) {
                return NULL;
            }
            Node * n = new Node(begin, end);
            if (begin == end) {
                return n;
            }
            int mid = begin + (end - begin) / 2;
            n->left = f1(begin, mid);
            n->right = f1(mid + 1, end);
            return n;
        }
        void insert(int id) {
            f2(root, id);
        }
        void f2(Node * n, int id) {
            if (!n) {
                return;
            }
            if (id < n->a or n->b < id) {
                return;
            }
            ++(n->c);
            int mid = n->a + (n->b - n->a) / 2;
            if (id <= mid) {
                f2(n->left, id);
            }
            else {
                f2(n->right, id);
            }
        }
        int query(int begin, int end) {
            return f3(root, begin, end);
        }
        int f3(Node * n, int begin, int end) {
            if (!n) {
                return 0;
            }
            if (begin > end) {
                return 0;
            }
            if (n->b < begin or end < n->a) {
                return 0;
            }
            if (begin <= n->a and n->b <= end) {
                return n->c;
            }
            int mid = n->a + (n->b - n->a) / 2;
            if (end <= mid) {
                return f3(n->left, begin, end);
            }
            if (mid + 1 <= begin) {
                return f3(n->right, begin, end);
            }
            return f3(n->left, begin, mid) + f3(n->right, mid + 1, end);
        }
    };
};