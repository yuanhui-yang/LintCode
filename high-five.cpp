// High Five
// http://www.lintcode.com/en/problem/high-five/

/*
There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.

Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]

Return 
*/

/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
	/**
	 * @param results a list of <student_id, score>
	 * @return find the average of 5 highest scores for each person
	 * map<int, double> (student_id, average_score)
	 */
	map<int, double> highFive(vector<Record>& results) {
		// Write your code here
		unordered_map<int, priority_queue<double, vector<double>, greater<double>>> dict;
		for (const auto & i : results) {
			dict[i.id].push(i.score);
			if (dict[i.id].size() > 5) {
				dict[i.id].pop();
			}
		}
		map<int, double> result;
		for (auto & i : dict) {
			double sum = 0, sz = i.second.size();
			while (!i.second.empty()) {
				sum += i.second.top();
				i.second.pop();
			}
			result[i.first] = sum / sz;
		}
		return result;
	}
};