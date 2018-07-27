/*148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/* 常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等。。
它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，
而根据单链表的特点，最适于用归并排序 */

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
    ListNode* sortList(ListNode *head){
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        ListNode *pre = head;
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }

    ListNode* merge(ListNode *l1, ListNode *l2){
        if (!l1) return l2;
        if (!l2) return l1;
        while (l1 || l2){
            int n1 = l1? l1->val : 0;
            int n2 = l2? l2->val : 0;
            if (n1 < n2) {
                l1->next = merge(l1->next, l2);
                return l1;
            } else {
                l2->next = merge(l2->next, l1);
                return l2;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
    }
};







