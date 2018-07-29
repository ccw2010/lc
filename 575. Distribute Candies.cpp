/* 575. Distribute Candies

Given an integer array with even length, where different numbers in this array represent different 
kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these 
candies equally in number to brother and sister. Return the maximum number of kinds of candies the 
sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation: There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 

Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
*/

/* Set - O(n) time, O(n) space
We can use a set to count all unique kinds of candies, but even all candies are unique, 
the sister cannot get more than half.
*/

/*这道题给我们一堆糖，每种糖的个数不定，分给两个人，让我们求其中一个人能拿到的最大的糖的种类数。
那么我们想，如果总共有n个糖，平均分给两个人，每人得到n/2块糖，那么能拿到的最大的糖的种类数也就是n／2种，
不可能再多，只可能再少。那么我们要做的就是统计出总共的糖的种类数，如果糖的种类数小于n/2，说明拿不到n/2种糖，
最多能拿到的种类数数就是当前糖的总种类数，明白了这点就很容易了，我们利用集合set的自动去重复特性来求出糖的种类数，
然后跟n/2比较，取二者之中的较小值返回即可*/


#include <unordered_set>
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (int c : candies){
            s.insert(c);
        }
        return min(s.size(), candies.size()/2);
    }
};





