/*135. Candy

There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
*/

/*先来看看两遍遍历的解法，首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，如果右边的小盆友的等级高，
等加一个糖果，这样保证了一个方向上高等级的糖果多。然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，
则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n, 1);
        for (int i = 0; i < n-1; i++) {
            if (ratings[i+1] > ratings[i]){ 
                nums[i+1] = nums[i] + 1;
            }
        }
        for (int i = n-1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) {
                nums[i-1] = max(nums[i-1], nums[i]+1);
            }
        }
        int res = 0;
        for (int n : nums) res += n;
        return res;
    }
};