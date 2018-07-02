/* 456. 132 Pattern

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that 
i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks 
whether there is a 132 pattern in the list.
Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [3, 1, 4, 2]
Output: True
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0]*/

/*这道题给我们了一个数组，让我们找到132的模式，就是第一个数小于第二第三个数，且第三个数小于第二个数。那么我们就按顺序
来找这三个数，首先我们来找第一个数，这个数需要最小，那么我们如果发现当前数字大于等于后面一个数字，我们就往下继续遍历，
直到当前数字小于下一个数字停止。然后我们找第二个数字，这个数字需要最大，那么如果我们发现当前数字小于等于下一个数字就
继续遍历，直到当前数字大雨下一个数字停止。最后就找第三个数字，我们验证这个数字是否在之前两个数字的中间，如果没有找到，
我们就从第二个数字的后面一个位置继续开始重新找这三个数字*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        int n = nums.size();
        int i = 0, j = 0, k = 0;
        while (i < n) {
            while (i < n-1 && nums[i] >= nums[i+1]) i++;
            j = i + 1;
            while (j < n-1 && nums[j] <= nums[j+1]) j++;
            for (k = j + 1; k < n; k++) {
                if (nums[k] > nums[i] && nums[k] < nums[j]) return true;
            }
            i = j + 1;
        }
        return false;
    }
};


/*下面这种方法利用来栈来做，既简洁又高效，思路是我们维护一个栈和一个变量third，其中third就是第三个数字，
也是pattern 132中的2，栈里面按顺序放所有大于third的数字，也是pattern 132中的3，那么我们在遍历的时候，
如果当前数字小于third，即pattern 132中的1找到了，我们直接返回true即可，因为已经找到了，注意我们应该从后
往前遍历数组。如果当前数字大于栈顶元素，那么我们按顺序将栈顶数字取出，赋值给third，然后将该数字压入栈，这样
保证了栈里的元素仍然都是大于third的，我们想要的顺序依旧存在，进一步来说，栈里存放的都是可以维持 
second > third的second值，其中的任何一个值都是大于当前的third值，如果有更大的值进来，那就等于形成了一个更优
的second > third的这样一个组合，并且这时弹出的third值比以前的third值更大，为什么要保证third值更大，因为这样
才可以更容易的满足当前的值first比third值小这个条件 */
 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> s;
        int n = nums.size();
        for (int i = n- 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); 
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};







