/* 554. Brick Wall

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
The bricks have the same height but different width. You want to draw a vertical line from the 
top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the 
width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need 
to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line 
will obviously cross no bricks.

Example:
Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation: 

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. 
Total number of bricks of the wall won't exceed 20,000. */

/*这道题给了我们一个砖头墙壁，上面由不同的长度的砖头组成，让我们选个地方从上往下把墙劈开，使得被劈开的砖头个数最少，
前提是不能从墙壁的两边劈。我们可使用一个哈希表来建立每一个断点的长度和其出现频率之间的映射*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto w : wall) {
            int sum = 0;
            for (int i = 0; i < w.size() - 1; i++) {
                sum += w[i];
                m[sum]++;
                res = max(res, m[sum]);
            }
        }
        return wall.size() - res;
    }
};





