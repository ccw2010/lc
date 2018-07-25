/* 120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent 
numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &t) {
        int row = t.size();
        for (int i = 1; i < row; i++) {
            int n = t[i].size();
            for (int j = 0; j < n; j++) {
                if (j==0) t[i][j] += t[i-1][j];
                else if (j==n-1) t[i][j] += t[i-1][j-1];
                else t[i][j] += min(t[i-1][j-1], t[i-1][j]);
            }
        }
        vector<int> lastRow = t[row-1];
        int res = lastRow[0];
        for (int i = 0; i < lastRow.size(); i++) {
            res = min(res, lastRow[i]);
        }
        return res;
    }
};






