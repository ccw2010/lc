/* 234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up: Could you do it in O(n) time and O(1) space?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*这道题让我们判断一个链表是否为回文链表，链表比字符串难的地方就在于不能通过坐标来直接访问，而只能从头开始
遍历到某个位置。那么根据回文串的特点，我们需要比较对应位置的值是否相等，那么我们首先需要找到链表的中点，这
个可以用快慢指针来实现，我们使用快慢指针找中点的原理是fast和slow两个指针，每次快指针走两步，慢指针走一步，
等快指针走完时，慢指针的位置就是中点。我们还需要用栈，每次慢指针走一步，都把值存入栈中，等到达中点时，链表
的前半段都存入栈中了，由于栈的后进先出的性质，就可以和后半段链表按照回文对应的顺序比较了*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        stack<int> s;
        ListNode *slow = head;
        ListNode *fast = head;
        s.push(head->val);
        while (fast->next && fast->next->next){
            slow = slow->next;
            s.push(slow->val);
            fast = fast->next->next;
        }
        if (!fast->next) s.pop();
        while (slow->next){
            slow = slow->next;
            int temp = s.top();
            s.pop();
            if (temp != slow->val) return false;
        }
        return true;    
    }
};






