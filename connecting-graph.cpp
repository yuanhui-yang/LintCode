// Connecting Graph
// http://www.lintcode.com/en/problem/connecting-graph/
// Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.
// You need to support the following method:
// 1. connect(a, b), add an edge to connect node a and node b. 2.query(a, b)`, check if two nodes are connected
// Example
// 5 // n = 5
// query(1, 2) return false
// connect(1, 2)
// query(1, 3) return false
// connect(2, 4)
// query(1, 4) return true
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class ConnectingGraph {
public:
	ConnectingGraph(int n) {
		// initialize your data structure here.
		father.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) father[i] = i;
	}

	void  connect(int a, int b) {
		// Write your code here
		int root_a = find(a);
		int root_b = find(b);
		if (root_a != root_b) father[root_a] = root_b;
	}

	bool query(int a, int b) {
		// Write your code here
		return find(a) == find(b);
	}
private:
	vector<int> father;
	int find(int x) {
		if (x == father[x]) return x;
		return father[x] = find(father[x]);
	}
};
// class ConnectingGraph {
// public:
// 	ConnectingGraph(int n) {
// 	// initialize your data structure here.
// 		father.resize(n, 0);
// 		for (int i = 0; i < n; i++) father[i] = i;
// 	}

// 	void  connect(int a, int b) {
// 	// Write your code here
// 		int root_a = find(a - 1);
// 		int root_b = find(b - 1);
// 		if (root_a != root_b) father[root_a] = root_b;
// 	}

// 	bool query(int a, int b) {
// 	// Write your code here
// 		return find(a - 1) == find(b - 1);
// 	}
// private:
// 	vector<int> father;
// 	int find(int x) {
// 		if (x == father[x]) return x;
// 		return father[x] = find(father[x]);
// 	}
// };
int main(void) {
	ConnectingGraph connectingGraph(5);
	assert(false == connectingGraph.query(1, 2));
	connectingGraph.connect(1, 2);
	assert(false == connectingGraph.query(1, 3));
	connectingGraph.connect(2, 4);
	assert(true == connectingGraph.query(1, 4));
	cout << "\nPassed All\n";
	return 0;
}