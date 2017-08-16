// 391. Number of Airplanes in the Sky
// http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/

/*
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

Have you met this question in a real interview? Yes
Example
For interval list

[
  [1,10],
  [2,3],
  [5,8],
  [4,7]
]
Return 3
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
	/**
	 * @param intervals: An interval array
	 * @return: Count of airplanes are in the sky.
	 */
	int countOfAirplanes(vector<Interval> &airplanes) {
		// write your code here
		sort(begin(airplanes), end(airplanes), Comp());
		priority_queue<int, vector<int>, greater<int>> pq;
		int result = 0, sz = airplanes.size();
		for (int i = 0; i < sz; ++i) {
			while (!pq.empty() and pq.top() <= airplanes[i].start) {
				pq.pop();
			}
			pq.push(airplanes[i].end);
			result = max(result, (int)pq.size());
		}
		return result;
	}
private:
	struct Comp {
		bool operator() (const Interval & a, const Interval & b) {
			return a.start < b.start;
		}
	};
};

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
	/**
	 * @param intervals: An interval array
	 * @return: Count of airplanes are in the sky.
	 */
	int countOfAirplanes(vector<Interval> &airplanes) {
		// write your code here
		vector<array<int, 2>> A;
		for (const auto & i : airplanes) {
			A.push_back({i.start, 1});
			A.push_back({i.end, -1});
		}
		sort(begin(A), end(A));
		int result = INT_MIN, curr = 0;
		for (const auto & i : A) {
			if (i[1] > 0) {
				++curr;
			}
			else {
				--curr;
			}
			result = max(result, curr);
		}
		return result < 0 ? 0 : result;
	}
};