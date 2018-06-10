/*477. Total Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding 
bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2
Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 

Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
 

这道题是461.Hamming Distance的拓展，由于有之前那道题的经验，我们知道需要用异或来求每个位上的情况，
那么我们需要来找出某种规律来，比如我们看下面这个例子，4，14，2和1：

4:     0 1 0 0

14:    1 1 1 0

2:     0 0 1 0

1:     0 0 0 1

我们先看最后一列，有三个0和一个1，那么它们之间相互的汉明距离就是3，即1和其他三个0分别的距离累加，然后在看第三列，
累加汉明距离为4，因为每个1都会跟两个0产生两个汉明距离，同理第二列也是4，第一列是3。我们仔细观察累计汉明距离和0跟1的个数，
我们可以发现其实就是0的个数乘以1的个数，发现了这个重要的规律，那么整道题就迎刃而解了，只要统计出每一位的1的个数即可*/


/*O(n) C++ bitwise solution with thinking process and explanation

1. Problem

The problem is to find the total Hamming distance between all pairs of the given numbers.

2. Thinking process

2.1 For one pair

When you calculate Hamming distance between x and y, you just

    calculate p = x ^ y;
    count the number of 1's in p

The distance from x to y is as same as y to x.

2.2 Trivial approach

For a series of number: a1, a2, a3,..., an

Use the approach in 2.1
(suppose distance(x, y) is the Hamming distance between x and y):

For a1, calculate S(1) = d(a1, a2) + d(a1, a3) + ... + d(a1, an)
For a2, calculate S(2) = d(a2, a3) + d(a2, a4) + ... + d(a2, an)
......
For a(n - 1), calculate S(n - 1) = d(a(n-1), a(n))

Finally , S = S(1) + S(2) + ... + S(n - 1).

The function distance is called 1 + 2 + ... + (n - 1) = n(n - 1)/2 times! That's too much!

2.3 New idea

The total Hamming distance is constructed bit by bit in this approach.

Let's take a series of number: a1, a2, a3,..., an

Just think about all the Least Significant Bit (LSB) of a(k) (1 ≤ k ≤ n).

How many Hamming distance will they bring to the total?

    If a pair of number has same LSB, the total distance will get 0.

    If a pair of number has different LSB, the total distance will get 1.

For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and
q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

    The total Hamming distance will get pq from LSB.

If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again 
until all numbers becomes zero

2.4 Time complexity

In each loop, we need to visit all numbers in nums to calculate how many numbers has 0 (or 1) as LSB.

If the biggest number in nums[] is K, the total number of loop is [logK] + 1.

So, the total time complexity of this approach is O(n).*/


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, len = nums.size();
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int n : nums) {
                int b = (1 << i);
                if (n & b) count++;
            }
            res += count * (len - count);
        }
        return res;
    }
};





