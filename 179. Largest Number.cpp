/*179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:
Input: [10,2]
Output: "210"

Example 2:
Input: [3,30,34,5,9]
Output: "9534330"
*/


class Solution {
public:
    static bool compare(int a, int b){
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    string largestNumber(vector<int>& nums) {
          sort(nums.begin(), nums.end(), compare);
          string res;
          for (int n : nums){
            res += to_string(n);
          }
          if (res[0] == '0') return "0";
          else return res; 
    }
};






