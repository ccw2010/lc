/*473. Matchsticks to Square

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl 
has, please find out a way you can make one square by using up all those matchsticks. You should not break 
any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will 
either be true or false, to represent whether you could make one square using all the matchsticks the little
match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
*/

/*这道题让我们用数组中的数字来摆出一个正方形。跟416.Partition Equal Subset Sum有点像，那道题问我们能不能
将一个数组分成和相等的两个子数组，而这道题实际上是让我们将一个数组分成四个和相等的子数组。一开始尝试着用那题
的解法来做，首先来判断数组之和是否是4的倍数，然后还是找能否分成和相等的两个子数组，但是在遍历的时候加上判断
如果数组中某一个数字大于一条边的长度时返回false。最后我们同时检查dp数组中一条边长度位置上的值跟两倍多一条边
长度位置上的值是否为true，这种方法不幸TLE了。所以只能上论坛求助各路大神了，发现了可以用优化过的递归来解，
递归的方法基本上等于brute force，但是C++版本的直接递归没法通过OJ，而是要先给数组从大到小的顺序排序，这样大
的数字先加，如果超过target了，就直接跳过了后面的再次调用递归的操作，效率会提高不少，所以会通过OJ。下面来看代码，
我们建立一个长度为4的数组sums来保存每个边的长度和，我们希望每条边都等于target，数组总和的四分之一。然后我们遍历
sums中的每条边，我们判断如果加上数组中的当前数字大于target，那么我们跳过，如果没有，我们就加上这个数字，然后对
数组中下一个位置调用递归，如果返回为真，我们返回true，否则我们再从sums中对应位置将这个数字减去继续循环*/


class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sums, 0, sum / 4);
    }
    bool dfs(vector<int>& nums, vector<int>& sums, int pos, int target) {
        if (pos >= nums.size()) {
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + nums[pos] > target) continue;
            sums[i] += nums[pos];
            if (dfs(nums, sums, pos + 1, target)) return true;
            sums[i] -= nums[pos];
        }
        return false;
    }
};











