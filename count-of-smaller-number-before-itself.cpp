// Count of Smaller Number before itself
// http://www.lintcode.com/en/problem/count-of-smaller-number-before-itself/

/*
Give you an integer array (index from 0 to n-1, where n is the size of this array, data value from 0 to 10000) . For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.

 Notice

We suggest you finish problem Segment Tree Build, Segment Tree Query II and Count of Smaller Number first.

Have you met this question in a real interview? Yes
Example
For array [1,2,7,8,5], return [0,1,2,3,2]
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        if (A.empty()) {
            return {};
        }
        Tree tree(0, 10000);
        vector<int> result;
        for (const auto &i : A) {
            result.push_back(tree.query(0, i - 1));
            tree.insert(i);
        }
        return result;
    }
private:
    struct Node {
        int begin, end, count;
        Node * left, * right;
        Node(int begin, int end) {
            this->begin = begin;
            this->end = end;
            this->count = 0;
            this->left = NULL;
            this->right = NULL;
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
            Node * node = new Node(begin, end);
            if (begin == end) {
                return node;
            }
            int mid = begin + (end - begin) / 2;
            node->left = f1(begin, mid);
            node->right = f1(mid + 1, end);
            return node;
        }
        void insert(int id) {
            f2(root, id);
        }
        void f2(Node * node, int id) {
            if (!node) {
                return;
            }
            if (id < node->begin or node->end < id) {
                return;
            }
            ++(node->count);
            int mid = node->begin + (node->end - node->begin) / 2;
            if (id <= mid) {
                f2(node->left, id);
            }
            else {
                f2(node->right, id);
            }
        }
        int query(int begin, int end) {
            return f3(root, begin, end);
        }
        int f3(Node * node, int begin, int end) {
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
                return node->count;
            }
            int mid = node->begin + (node->end - node->begin) / 2;
            if (end <= mid) {
                return f3(node->left, begin, end);    
            }
            if (mid + 1 <= begin) {
                return f3(node->right, begin, end);
            }
            return f3(node->left, begin, mid) + f3(node->right, mid + 1, end);;
        }
    };
};