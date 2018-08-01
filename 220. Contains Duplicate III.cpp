/*220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in 
the array such that the absolute difference between nums[i] and nums[j] is at most t and the 
absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

/*这道题跟 217.Contains Duplicate 和 219.Contains Duplicate II 的关联并不是很大，
前两道起码跟重复值有关，这道题的焦点不是在重复值上面，反而是关注与不同的值之间的关系，这里有两个限制条件，
两个数字的坐标差不能大于k，值差不能大于t。这道题如果用brute force会超时，所以我们只能另辟蹊径。这里我们使用
map数据结构来解,用来记录数字和其下标之间的映射。 这里需要两个指针i和j，刚开始i和j都指向0，然后i开始向右遍历
数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都不大于k，然后我们用
map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，所有小于这个阈值的数和
nums[i]的差的绝对值会大于t (可自行带数检验)。然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回
true。最后遍历完整个数组返回false*/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - j > k) m.erase(nums[j++]);
            map<long, int>::iterator it = m.lower_bound((long)nums[i] - t);
            if (it != m.end() && abs(it->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s; // set is ordered automatically 
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto it = s.lower_bound((long)nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
            // x - nums[i] <= t ==> |x - nums[i]| <= t    
            if (it != s.end() && *it - nums[i] <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};







