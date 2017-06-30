// Interval Minimum Number
// http://www.lintcode.com/en/problem/interval-minimum-number/

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
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        if (A.empty()) {
            return {};
        }
        int n = A.size();
        Tree tree(0, n - 1);
        for (int i = 0; i < n; ++i) {
            tree.insert(i, A[i]);
        }
        vector<int> result;
        for (const auto &i : queries) {
            result.push_back(tree.query(i.start, i.end));
        }
        return result;
    }
private:
    struct Node {
        int begin, end, val;
        Node * left, * right;
        Node(int begin, int end) {
            this->begin = begin;
            this->end = end;
            this->val = numeric_limits<int>::max();
            this->left = NULL;
            this->right = NULL;
        }
    };
    struct Tree {
        Tree(int begin, int end) {
            this->root = f(begin, end);    
        }
        Node * f(int begin, int end) {
            if (begin > end) {
                return NULL;
            }
            Node * node = new Node (begin, end);
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
            node->val = min(node->val, val);
            g(node->left, index, val);
            g(node->right, index, val);
        }
        int query(int begin, int end) {
            return h(root, begin, end);
        }
        int h(Node * node, int begin, int end) {
            if (!node) {
                return numeric_limits<int>::max();
            }
            if (begin > end) {
                return numeric_limits<int>::max();
            }
            if (node->begin > end or node->end < begin) {
                return numeric_limits<int>::max();
            }
            if (begin <= node->begin and end >= node->end) {
                return node->val;
            }
            int mid = node->begin + (node->end - node->begin) / 2;
            if (end <= mid) {
                return h(node->left, begin, end);
            }
            if (begin >= mid + 1) {
                return h(node->right, begin, end);
            }
            return min(h(node->left, begin, mid), h(node->right, mid + 1, end));
        }
        Node * root;
    };
};