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

/* 这道链表重排序问题可以拆分为以下三个小问题：
1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。
2. 将第二个链翻转。
3. 将第二个链表的元素间隔地插入第一个链表中。 */

 /*A concise O(n) time, O(1) in place solution*/
class Solution {
public:
   void reorderList(ListNode *head) {
        if (!head || !head->next) return;
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
        ListNode *revHead = pre;
        while (head && revHead) {
            ListNode *next = head->next;
            head->next = revHead;
            revHead = revHead->next;
            head->next->next = next;
            head = next;
        }
    }
};






