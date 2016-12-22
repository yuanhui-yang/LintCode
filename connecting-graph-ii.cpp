// Connecting Graph II
// http://www.lintcode.com/en/problem/connecting-graph-ii/
// Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
// You need to support the following method:
// 1. connect(a, b), an edge to connect node a and node b
// 2. query(a), Returns the number of connected component nodes which include node a.
// Example
// 5 // n = 5
// query(1) return 1
// connect(1, 2)
// query(1) return 2
// connect(2, 4)
// query(1) return 3
// connect(1, 4)
// query(1) return 3
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class ConnectingGraph2 {
public:
	ConnectingGraph2(int n) {
		// initialize your data structure here.
		father.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) father[i] = i;
		size.resize(n + 1, 1);
		size[0] = 0;
	}

	void  connect(int a, int b) {
		// Write your code here
		int root_a = find(a);
		int root_b = find(b);
		if (root_a != root_b) {
			father[root_a] = root_b;
			size[root_b] += size[root_a];
		}
	}

	int query(int a) {
		// Write your code here
		int root_a = find(a);
		return size[root_a];
	}
private:
	vector<int> father;
	vector<int> size;
	int find(int x) {
		if (x == father[x]) return x;
		father[x] = find(father[x]);
		size[x] = size[father[x]];
		return father[x];
	}
};
int main(void) {
	ConnectingGraph2 connectingGraph2(5);
	assert(1 == connectingGraph2.query(1));
	connectingGraph2.connect(1, 2);
	assert(2 == connectingGraph2.query(1));
	connectingGraph2.connect(2, 4);
	assert(3 == connectingGraph2.query(1));
	connectingGraph2.connect(1, 4);
	assert(3 == connectingGraph2.query(1));
	cout << "\nPassed All\n";
	return 0;
}