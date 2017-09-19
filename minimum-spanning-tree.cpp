// Minimum Spanning Tree
// http://www.lintcode.com/en/problem/minimum-spanning-tree/

/*
Given a list of Connections, which is the Connection class (the city name at both ends of the edge and a cost between them), find some edges, connect all the cities and spend the least amount.
Return the connects if can connect all the cities, otherwise return empty list.

 Notice

Return the connections sorted by the cost, or sorted city1 name if their cost is same, or sorted city2 if their city1 name is also same.

Have you met this question in a real interview? Yes
Example
Gievn the connections = ["Acity","Bcity",1], ["Acity","Ccity",2], ["Bcity","Ccity",3]

Return ["Acity","Bcity",1], ["Acity","Ccity",2]
*/

/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */

struct Comp {
	bool operator() (const Connection & a, const Connection & b) {
		if (a.cost == b.cost) {
			if (a.city1 == b.city1) {
				return a.city2 < b.city2;
			}
			return a.city1 < b.city1;
		}
		return a.cost < b.cost;
	}
};

class Solution {
public:
	/**
	 * @param connections given a list of connections include two cities and cost
	 * @return a list of connections from results
	 */
	vector<Connection> lowestCost(vector<Connection>& connections) {
		sort(connections.begin(), connections.end(), Comp());
		unordered_map<string, int> labels;
		int n = 0;
		for (const auto & i : connections) {
			if (!labels.count(i.city1)) {
				labels[i.city1] = n;
				++n;
			}
			if (!labels.count(i.city2)) {
				labels[i.city2] = n;
				++n;
			}
		}
		vector<int> roots(n);
		iota(roots.begin(), roots.end(), 0);
		vector<Connection> result;
		for (const auto & i : connections) {
			int label1 = labels[i.city1], label2 = labels[i.city2];
			int root1 = getRoot(roots, label1), root2 = getRoot(roots, label2);
			if (root1 != root2) {
				roots[root1] = root2;
				--n;
				result.push_back(i);
			}
		}
		return n == 1 ? result : vector<Connection>();
	}
private:
	int getRoot(vector<int> & roots, int id) {
		return id == roots[id] ? id : roots[id] = getRoot(roots, roots[id]);
	}
};