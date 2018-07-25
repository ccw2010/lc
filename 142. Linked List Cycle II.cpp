/* 143. Linked List Cycle II 
 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up: Can you solve it without using extra space? */

/*这个求单链表中的环的起始点是之前那个判断单链表中是否有环的延伸，还是要设快慢指针，不过这次要记录两个指针相遇的位置，
当两个指针相遇了后，让其一指针从链表头开始遍历，此时再相遇的位置就是链表中环的起始位置。*/
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};







