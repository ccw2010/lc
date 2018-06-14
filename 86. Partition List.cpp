/*86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/*将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，
将原链表直接接在新链表后。此种解法链表变化顺序为：

Original: 1 -> 4 -> 3 -> 2 -> 5 -> 2 
New:

Original: 4 -> 3 -> 2 -> 5 -> 2 
New:　    1

Original: 4 -> 3 -> 5 -> 2 
New:　    1 -> 2

Original: 4 -> 3 -> 5 
New:　    1 -> 2 -> 2

Original: 
New:　    1 -> 2 -> 2 -> 4 -> 3 -> 5 
*/

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};





