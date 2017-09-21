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
		LinkedList[] A = new LinkedList[numCourses];
		for (int i = 0; i < numCourses; ++i) {
			A[i] = new LinkedList<Integer>();
		}
		int[] B = new int[numCourses];
		Arrays.fill(B, 0);
		for (int[] i : prerequisites) {
			A[i[1]].add(i[0]);
			++B[i[0]];
		}
		LinkedList<Integer> curr = new LinkedList<>(), C = new LinkedList<>();
		for (int i = 0; i < numCourses; ++i) {
			if (B[i] == 0) {
				curr.add(i);
			}
		}
		while (!curr.isEmpty()) {
			LinkedList<Integer> next = new LinkedList<>();
			for (Integer i : curr) {
				C.add(i);
				LinkedList<Integer> D = A[(int)i];
				for (Integer j : D) {
					--B[(int)j];
					if (B[(int)j] == 0) {
						next.add(j);
					}
				}
			}
			curr = next;
		}
		if (C.size() != numCourses) {
			return new int[0];
		}
		int[] result = new int[numCourses];
		int i = 0;
		for (Integer j : C) {
			result[i++] = j;
		}
		return result;
	}
}