/* 506. Relative Ranks
Given scores of N athletes, find their relative ranks and the people with the top three highest scores,
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", 
"Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks 
according to their scores. */

/*这道题给了我们一组分数，让我们求相对排名，前三名分别是金银铜牌，后面的就是名次数，我们可以利用堆来排序，建立一个优先队列，
把分数和其坐标位置放入队列中，会自动按其分数高低排序，然后我们从顶端开始一个一个取出数据，由于保存了其在原数组的位置，我们
可以直接将其存到结果res中正确的位置，用一个变量k来记录名词，前三名给奖牌，后面就是名次数*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n, "");
        priority_queue<pair<int,int>> q;
        for (int i=0; i<n; i++){
            q.push({nums[i], i});
        }
        int k = 1;
        while (!q.empty()){
            int i = q.top().second;
            q.pop();
            if (k==1) res[i] = "Gold Medal";
            else if (k==2) res[i] = "Silver Medal";
            else if (k==3) res[i] = "Bronze Medal";
            else res[i] = to_string(k);
            k++;
        }
        return res;
    }
};








