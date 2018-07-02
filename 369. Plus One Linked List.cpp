/*369. Plus One Linked List

Given a non-negative integer represented as non-empty a singly linked list of digits, 
plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:

Input:
1->2->3

Output:
1->2->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return NULL;
        int carry = plus(head);
        if (carry) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        } else { 
            return head;
        }
    }

    int plus(ListNode *node) {
        if (!node) return 1;
        int carry = plus(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};





