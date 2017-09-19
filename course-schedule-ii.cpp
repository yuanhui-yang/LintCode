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

class Solution {
public:
	/**
	 * @param numCourses a total of n courses
	 * @param prerequisites a list of prerequisite pairs
	 * @return the course order
	 */
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> graph(numCourses);
		for (const auto & i : prerequisites) {
			++indegree[i.first];
			graph[i.second].push_back(i.first);
		}
		vector<int> curr, result;
		for (int i = 0; i < numCourses; ++i) {
			if (indegree[i] == 0) {
				curr.push_back(i);
			}
		}
		while (!curr.empty()) {
			vector<int> next;
			for (const auto & i : curr) {
				result.push_back(i);
				for (const auto & j : graph[i]) {
					if (--indegree[j] == 0) {
						next.push_back(j);
					}
				}
			}
			curr = next;
		}
		for (const auto & i : indegree) {
			if (i > 0) {
				return {};
			}
		}
		return result;
		
	}
};