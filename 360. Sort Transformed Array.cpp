/* 360. Sort Transformed Array

Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of 
the form f(x) = ax^2 + bx + c to each element x in the array.

The returned array must be in sorted order.
Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
Result: [-23, -5, 1, 7]
*/


/*这道题给了我们一个数组，又给了我们一个抛物线的三个系数，让我们求带入抛物线方程后求出的数组成的有序数组。
那么我们首先来看O(nlgn)的解法，这个解法没啥可说的，就是每个算出来再排序，这里我们用了最小堆来帮助我们排序*/

#include <queue>
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto x : nums) {
            q.push(a * x * x + b * x + c);
        }
        while (!q.empty()) {
            res.push_back(q.top()); 
            q.pop();
        }
        return res;
    }
};

/*但题目要求让我们在O(n)中实现，那么我们只能另辟蹊径。其实这道题用到了大量的高中所学的关于抛物线的数学知识，
我们知道，对于一个方程f(x) = ax^2 + bx + c 来说，如果a>0，则抛物线开口朝上，那么两端的值比中间的大，而如果a<0，
则抛物线开口朝下，则两端的值比中间的小。而当a=0时，则为直线方法，是单调递增或递减的。那么我们可以利用这个性质来解题，
题目中说明了给定数组nums是有序的，如果不是有序的，很难有O(n)的解法。正因为输入数组是有序的，我们根据a来分情况讨论：

当a>0，说明两端的值比中间的值大，那么此时我们从结果res后往前填数，用两个指针分别指向nums数组的开头和结尾，指向的两个数
就是抛物线两端的数，将它们之中较大的数先存入res的末尾，然后指针向中间移，重复比较过程，直到把res都填满。

当a<0，说明两端的值比中间的小，那么我们从res的前面往后填，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线
两端的数，将它们之中较小的数先存入res的开头，然后指针向中间移，重复比较过程，直到把res都填满。

当a=0，函数是单调递增或递减的，那么从前往后填和从后往前填都可以，我们可以将这种情况和a>0合并*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> res(n);
        int idx = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            int y1 = fx(nums[i], a, b, c);
            int y2 = fx(nums[j], a, b, c);
            if (a >= 0) {
                if ( y1 >= y2) {res[idx--] = y1; i++;}
                else {res[idx--] = y2; j--;}
            } else {
                if ( y1 >= y2) {res[idx++] = y2; j--;}
                else {res[idx++] = y1; i++;}
            }
        }
        return res;
    }
    int fx(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};









