/*149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4

Example 2:
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

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
    int maxPoints(vector<Point> &points) {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> m;
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                Point pi = points[i];
                Point pj = points[j];
                if (pi.x == pj.x && pi.y == pj.y) {
                    count++; continue;
                } 
                int dx = pj.x - pi.x;
                int dy = pj.y - pi.y;
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, count);
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + count);
            }
        }
        return res;
        }
    int gcd(int a, int b) {
            return (b == 0) ? a : gcd(b, a % b);
    }
};










