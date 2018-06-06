/*143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*A concise O(n) time, O(1) in place solution*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *l2 = mid;
        ListNode *pre = NULL;
        while (l2) {
            ListNode *next = l2->next;
            l2->next = pre;
            pre = l2;
            l2 = next;
        }
        while (head && l2) {
            ListNode *next = head->next;
            head->next = l2;
            head->next->next = next;
            head = next;
            l2 = l2->next;
        }
    }
};







