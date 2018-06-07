/*223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.
https://leetcode.com/problems/rectangle-area/description/

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
*/

/*首先尝试先找出所有的不相交的情况，只有四种，一个矩形在另一个的上下左右四个位置不重叠，这四种情况下返回两个矩形
面积之和。其他所有情况下两个矩形是有交集的，这时候我们只要算出长和宽，即可求出交集区域的大小，然后从两个巨型面积
之和中减去交集面积就是最终答案。求交集区域的长和宽也不难，由于交集都是在中间，所以横边的左端点是两个矩形左顶点横
坐标的较大值，右端点是两个矩形右顶点的较小值，同理，竖边的下端点是两个矩形下顶点纵坐标的较大值，上端点是两个矩形
上顶点纵坐标的较小值*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 =  (H-F) * (G-E);
        int sum = area1 + area2;
        
        if (E >= C || F >= D || B >= H || A >= G) {
            return sum;
        }else{
            int width = min(G, C) - max(A, E);
            int height = min(D, H) - max(B, F);
            return sum - width * height;
        }
    }
};













