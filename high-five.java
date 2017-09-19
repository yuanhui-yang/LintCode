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
 *     public int id, score;
 *     public Record(int id, int score){
 *         this.id = id;
 *         this.score = score;
 *     }
 * }
 */
public class Solution {
	/**
	 * @param results a list of <student_id, score>
	 * @return find the average of 5 highest scores for each person
	 * Map<Integer, Double> (student_id, average_score)
	 */
	public Map<Integer, Double> highFive(Record[] results) {
		HashMap<Integer, PriorityQueue<Integer>> dict = new HashMap<>();
		for (Record i : results) {
			if (!dict.containsKey(i.id)) {
				dict.put(i.id, new PriorityQueue<Integer>());
			}
			dict.get(i.id).add(i.score);
			if (dict.get(i.id).size() > 5) {
				dict.get(i.id).poll();
			}
		}
		Map<Integer, Double> result = new HashMap<>();
		for (Map.Entry<Integer, PriorityQueue<Integer>> i : dict.entrySet()) {
			int id = i.getKey();
			PriorityQueue<Integer> scores = i.getValue();
			double sum = 0, sz = (double)scores.size();
			while (!scores.isEmpty()) {
				sum += scores.poll();
			}
			result.put(id, sum / sz);
		}
		return result;
	}
}