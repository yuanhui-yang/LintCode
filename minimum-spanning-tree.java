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
 * public class Connection {
 *   public String city1, city2;
 *   public int cost;
 *   public Connection(String city1, String city2, int cost) {
 *       this.city1 = city1;
 *       this.city2 = city2;
 *       this.cost = cost;
 *   }
 * }
 */
public class Solution {
	/**
	 * @param connections given a list of connections include two cities and cost
	 * @return a list of connections from results
	 */
	public List<Connection> lowestCost(List<Connection> connections) {
		Collections.sort(connections, new Comp());
		int n = 0;
		Map<String, Integer> dict = new HashMap<String, Integer>();
		for (Connection i : connections) {
			if (!dict.containsKey(i.city1)) {
				dict.put(i.city1, n);
				++n;
			}
			if (!dict.containsKey(i.city2)) {
				dict.put(i.city2, n);
				++n;
			}
		}
		int[] roots = new int[n];
		for (int i = 0; i < n; ++i) {
			roots[i] = i;
		}
		List<Connection> result = new LinkedList<Connection>();
		for (Connection i : connections) {
			int label1 = dict.get(i.city1), label2 = dict.get(i.city2);
			int root1 = getRoot(roots, label1), root2 = getRoot(roots, label2);
			if (root1 != root2) {
				--n;
				roots[root1] = root2;
				result.add(i);
			}
		}
		if (n == 1) {
			return result;
		}
		return new LinkedList<Connection>();
	}
	private class Comp implements Comparator<Connection> {
		public int compare(Connection a, Connection b) {
			if (a.cost == b.cost) {
				if (a.city1.equals(b.city1)) {
					return a.city2.compareTo(b.city2);
				}
				return a.city1.compareTo(b.city1);
			}
			return a.cost - b.cost;
		}
	}
	private int getRoot(int[] roots, int id) {
		if (id == roots[id]) {
			return id;
		}
		int result = getRoot(roots, roots[id]);
		return roots[id] = result;
	}
}