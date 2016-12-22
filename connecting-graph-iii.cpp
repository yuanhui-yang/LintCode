// Connecting Graph III
// http://www.lintcode.com/en/problem/connecting-graph-iii/
// Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
// You need to support the following method:
// 1. connect(a, b), an edge to connect node a and node b
// 2. query(), Returns the number of connected component in the graph
// Example
// 5 // n = 5
// query() return 5
// connect(1, 2)
// query() return 4
// connect(2, 4)
// query() return 3
// connect(1, 4)
// query() return 3
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class ConnectingGraph3 {
public:
	ConnectingGraph3(int n) {
		// initialize your data structure here.
		cnt = n;
		father.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) father[i] = i;
	}

	void  connect(int a, int b) {
		// Write your code here
		int root_a = find(a);
		int root_b = find(b);
		if (root_a != root_b) {
			father[root_a] = root_b;
			cnt--;
		}
	}

	int query() {
		// Write your code here
		return cnt;
	}
private:
	int cnt;
	vector<int> father;
	int find(int x) {
		if (x == father[x]) return x;
		return father[x] = find(father[x]);
	}
};
int main(void) {
	ConnectingGraph3 connectingGraph3(5);
	assert(5 == connectingGraph3.query());
	connectingGraph3.connect(1, 2);
	assert(4 == connectingGraph3.query());
	connectingGraph3.connect(2, 4);
	assert(3 == connectingGraph3.query());
	connectingGraph3.connect(1, 4);
	assert(3 == connectingGraph3.query());
	cout << "\nPassed All\n";
	return 0;
}