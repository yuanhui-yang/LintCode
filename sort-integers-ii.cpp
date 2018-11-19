class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        quick_sort(A, 0, A.size());
    }
private:
    void quick_sort(vector<int> &A, int begin, int end)
    {
        int sz = end - begin;
        if (sz <= 1)
        {
            return;
        }
        int pivot = partition(A, begin, end);
        quick_sort(A, begin, pivot);
        quick_sort(A, pivot + 1, end);
    }
    int partition(vector<int> &A, int begin, int end)
    {
        int & pivot = A[begin];
        int i = begin + 1, j = end - 1;
        while (i <= j)
        {
            if (A[i] <= pivot)
            {
                ++i;
            }
            else if (A[j] >= pivot)
            {
                --j;
            }
            else
            {
                swap(A[i++], A[j--]);
            }
        }
        swap(pivot, A[j]);
        return j;
    }
};

class Solution {
public:
    /*
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers2(vector<int>& A) {
        // write your code here
        partial_sort(A, 0, A.size());
        
        // queue<array<int, 2>> q;
        // q.push({0, A.size()});
        // while (!q.empty()) {
        //     array<int, 2> front = q.front();
        //     q.pop();
        //     int begin = front[0], end = front[1];
        //     if (end - begin > 1) {
        //         int partition = quick_select(A, begin, end);
        //         q.push({begin, partition});
        //         q.push({partition + 1, end});
        //     }
        // }
        
        // stack<array<int, 2>> s;
        // s.push({0, A.size()});
        // while (!s.empty()) {
        //     array<int, 2> top = s.top();
        //     s.pop();
        //     int begin = top[0], end = top[1];
        //     if (end - begin > 1) {
        //         int partition = quick_select(A, begin, end);
        //         s.push({begin, partition});
        //         s.push({partition + 1, end});
        //     }
        // }
    }
private:
    int quick_select(vector<int>& A, int begin, int end) {
        int i = begin + 1, j = end;
        while (i < j) {
            if (A[i] <= A[begin]) {
                ++i;
            }
            else if (A[j - 1] >= A[begin]) {
                --j;
            }
            else {
                swap(A[i], A[j - 1]);
            }
        }
        swap(A[begin], A[i - 1]);
        return i - 1;
    }
    void partial_sort(vector<int>& A, int begin, int end) {
        if (end - begin <= 1) {
            return;
        }
        int partition = quick_select(A, begin, end);
        partial_sort(A, begin, partition);
        partial_sort(A, partition + 1, end);
    }
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> & A) {
        // write your code here
        heap_sort(A);
    }
private:
    void heap_sort(vector<int> & A) {
        build_maxheap(A);
        int sz = A.size();
        for (int i = sz - 1; i >= 0; --i) {
            swap(A[0], A[i]);
            max_heapify(A, 0, i);
        }
    }
    void build_maxheap(vector<int> & A) {
        int sz = A.size();
        for (int i = sz / 2 - 1; i >= 0; --i) {
            max_heapify(A, i, sz);
        }
    }
    void max_heapify(vector<int> & A, int i, int N) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < N and A[largest] < A[left]) {
            largest = left;
        }
        if (right < N and A[largest] < A[right]) {
            largest = right;
        }
        if (largest != i) {
            swap(A[largest], A[i]);
            max_heapify(A, largest, N);
        }
    }
};
