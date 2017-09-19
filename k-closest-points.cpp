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
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

Point c;
struct Comp {
	bool operator() (const Point & a, const Point & b) const {
		int d1 = distance(a, c), d2 = distance(b, c);
		if (d1 == d2) {
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x < b.x;
		}
		return d1 < d2;
	}
	int distance(const Point & a, const Point & c) const {
		return (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
	}
};

class Solution {
public:
	/*
	 * @param points: a list of points
	 * @param origin: a point
	 * @param k: An integer
	 * @return: the k closest points
	 */
	vector<Point> kClosest(vector<Point> points, Point origin, int k) {
		c.x = origin.x;
		c.y = origin.y;
		priority_queue<Point, vector<Point>, Comp> pq;
		for (const auto & i : points) {
			pq.push(i);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		vector<Point> result(pq.size());
		int i = pq.size();
		while (!pq.empty()) {
			--i;
			result[i] = pq.top();
			pq.pop();
		}
		return result;
	}
};