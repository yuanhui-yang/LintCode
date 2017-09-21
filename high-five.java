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
		HashMap<Integer, PriorityQueue<Integer>> A = new HashMap<>();
		for (Record i : results) {
			if (!A.containsKey(i.id)) {
				A.put(i.id, new PriorityQueue<Integer>(5));
			}
			PriorityQueue<Integer> pq = A.get(i.id);
			pq.add(i.score);
			if (pq.size() > 5) {
				pq.poll();
			}
		}
		Map<Integer, Double> result = new HashMap<>();
		for (Map.Entry<Integer, PriorityQueue<Integer>> i : A.entrySet()) {
			PriorityQueue<Integer> pq = i.getValue();
			double sum = 0, sz = pq.size();
			while (!pq.isEmpty()) {
				sum += pq.poll();
			}
			result.put(i.getKey(), sum / sz);
		}
		return result;
	}
}