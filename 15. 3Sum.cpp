/* 15. 3Sum
 
Given an array nums of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
 
For example, given array nums = {-1 0 1 2 -1 -4},
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
 
这道题让我们求三数之和，比 1.Two Sum要复杂一些，一开始考虑先fix一个数，然后另外两个数使用Two Sum那种HashMap的解法，
但是会有重复结果出现，就算使用set来去除重复也不行，会TLE，看来此题并不是考我们Two Sum的解法。那么我们来分析一下这道
题的特点，要我们找出三个数且和为0，那么除了三个数全是0的情况之外，肯定会有负数和正数，我们还是要先fix一个数，然后去找
另外两个数，我们只要找到两个数且和为第一个fix数的相反数就行了，既然另外两个数不能使用Two Sum的那种解法来找，如果能更
有效的定位呢？我们肯定不希望遍历所有两个数的组合吧，所以如果数组是有序的，那么我们就可以用双指针以线性时间复杂度来遍历
所有满足题意的两个数组合。

我们对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。这里我们可以
先做个剪枝优化，就是当遍历到正数的时候就break，为啥呢，因为我们的数组现在是有序的了，如果第一个要fix的数就是正数了，那
么后面的数字就都是正数，就永远不会出现和为0的情况了。然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和
前面的数字相等，就跳过，因为我们不想把相同的数字fix两次。对于遍历到的数，用0减去这个fix的数得到一个target，然后只需要
再之后找到两个数之和等于target即可。我们用两个指针分别指向fix数字之后开始的数组首尾两个数，如果两个数和正好为target，
则将这两个数和fix的数一起存入结果中。然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，
则我们将左边那个指针i右移一位，使得指向的数字增大一些。同理，如果两数之和大于target，则我们将右边那个指针j左移一位，使
得指向的数字减小一些 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k-1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i+1]) i++;
                    while (i < j && nums[j] == nums[j-1]) j--;
                    i++; j--;
                } else if (nums[i] + nums[j] < target) i++;
                else j--;
            }
        }
        return res;
    }
};








