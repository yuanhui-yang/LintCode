// Course Schedule II
// http://www.lintcode.com/en/problem/course-schedule-ii/

/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]
*/

public class Solution {
	/*
	 * @param numCourses: a total of n courses
	 * @param prerequisites: a list of prerequisite pairs
	 * @return: the course order
	 */
	public int[] findOrder(int numCourses, int[][] prerequisites) {
		// write your code here
		int[] indegree = new int[numCourses];
		Arrays.fill(indegree, 0);
		ArrayList[] graph = new ArrayList[numCourses];
		for (int i = 0; i < numCourses; ++i) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int[] i : prerequisites) {
			++indegree[i[0]];
			graph[i[1]].add(i[0]);
		}
		ArrayList<Integer> curr = new ArrayList<Integer>();
		for (int i = 0; i < numCourses; ++i) {
			if (indegree[i] == 0) {
				curr.add(i);
			}
		}
		int[] result = new int[numCourses];
		int id = 0;
		while (!curr.isEmpty()) {
			ArrayList<Integer> next = new ArrayList<Integer>();
			for (Integer i : curr) {
				result[id] = (int)i;
				++id;
				ArrayList<Integer> l = graph[(int)i];
				for (Integer j : l) {
					--indegree[(int)j];
					if (indegree[(int)j] == 0) {
						next.add((int)j);
					}
				}
			}
			curr = next;
		}
		for (int i : indegree) {
			if (i > 0) {
				return new int[0];
			}
		}
		return result;
	}
}