/* 206. Reverse Linked List

Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

/* Iterative solution: 在原链表之前建立一个dummy node，因为首节点会变，然后从head开始，
   将之后的一个节点移到dummy node之后，重复此操作知道head成为末节点为止 */
  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head; 
        while (cur && cur->next) {
            ListNode* temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next; 
            pre->next->next = temp;
        }
        return dummy->next;
    }
};


/* 递归解法的思路是，不断的进入递归函数，直到head指向最后一个节点，p指向之前一个节点，然后调换
head和p的位置，再返回上一层递归函数，再交换p和head的位置，每次交换后，head节点后面都是交换好
的顺序，直到p为首节点，然后再交换，首节点就成了为节点，此时整个链表也完成了翻转 */

// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};










