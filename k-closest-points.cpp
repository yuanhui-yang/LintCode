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

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Comp {
    static Point origin;
    bool operator() (const Point & a, const Point & b) {
        int x = f(a, origin), y = f(b, origin);
        if (x == y) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            else {
                return a.x < b.x;
            }
        }
        else {
            return x < y;
        }
    }
    int f(const Point & p, const Point & origin) {
        return (p.x - origin.x) * (p.x - origin.x) + (p.y - origin.y) * (p.y - origin.y); 
    }
};

Point Comp::origin = Point();

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        Comp::origin = origin;
        priority_queue<Point, vector<Point>, Comp> pq;
        for (const auto & i : points) {
            pq.push(i);
            while (pq.size() > k) {
                pq.pop();
            }
        }
        vector<Point> result(pq.size());
        while (!pq.empty()) {
            result[pq.size() - 1] = pq.top();
            pq.pop();
        }
        return result;
    }
};

Point c;
struct Comp {
	bool operator() (const Point & a, const Point & b) {
		int d1 = getDist(a, c), d2 = getDist(b, c);
		if (d1 == d2) {
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x < b.x;
		}
		return d1 < d2;
	}
	int getDist(const Point & a, const Point & b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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
		c = origin;
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
			result[--i] = pq.top();
			pq.pop();
		}
		return result;
	}
};
