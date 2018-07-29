/* 344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh". */

/* 这道题没什么难度，直接从两头往中间走，同时交换两边的字符即可 */

/* 直接从两头往中间走，同时交换两边的字符即可
Time complexity:  O(n)
Space complexity: O(1) */

class Solution {
public:
    string reverseString(string s) {    
        int left = 0, right = s.size() -1;
        while (left < right){
            swap(s[left++], s[right--]);
            /* char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp; */
        }
        return s;
    }
};




