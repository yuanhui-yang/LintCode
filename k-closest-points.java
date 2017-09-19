// K Closest Points
// http://www.lintcode.com/en/problem/k-closest-points/

/*
Given some points and a point origin in two dimensional space, find k points out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]
*/

/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */

public class Solution {
	public Point[] kClosest(Point[] points, Point origin, int k) {
		this.origin = origin;
		PriorityQueue<Point> pq = new PriorityQueue<Point>(k, new Comp());
		for (Point i : points) {
			pq.offer(i);
			if (pq.size() > k) {
				pq.poll();
			}
		}
		int i = pq.size();
		Point[] result = new Point[i];
		while (!pq.isEmpty()) {
			--i;
			result[i] = pq.poll();
		}
		return result;
	}
	private Point origin = null;
	private int distance(Point a, Point b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	private class Comp implements Comparator<Point> {
		@Override
		public int compare(Point a, Point b) {
			int d1 = distance(a, origin), d2 = distance(b, origin);
			if (d1 == d2) {
				if (a.x == b.x) {
					return b.y - a.y;
				}
				return b.x - a.x;
			}
			return d2 - d1;
		}
	}
}