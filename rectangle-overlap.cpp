// Rectangle Overlap
// http://www.lintcode.com/en/problem/rectangle-overlap/

/*
Given two rectangles, find if the given two rectangles overlap or not.

 Notice

l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

l1 != r2 and l2 != r2

Example
Given l1 = [0, 8], r1 = [8, 0], l2 = [6, 6], r2 = [10, 0], return true

Given l1 = [0, 8], r1 = [8, 0], l2 = [9, 6], r2 = [10, 0], return `false
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


class Solution {
public:
	/*
	 * @param l1: top-left coordinate of first rectangle
	 * @param r1: bottom-right coordinate of first rectangle
	 * @param l2: top-left coordinate of second rectangle
	 * @param r2: bottom-right coordinate of second rectangle
	 * @return: true if they are overlap or false
	 */
	bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
		if (r1.x < l2.x or r2.x < l1.x) {
			return false;
		}
		if (l2.y < r1.y or l1.y < r2.y) {
			return false;
		}
		return true;
	}
};