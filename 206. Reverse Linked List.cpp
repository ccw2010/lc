/*Iterative solution: 在原链表之前建立一个dummy node，因为首节点会变，然后从head开始，
将之后的一个节点移到dummy node之后，重复此操作知道head成为末节点为止*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = new_head;
        ListNode* cur = head; 
        while (cur && cur->next) {
            ListNode* temp = prev->next;
            pre->next = cur->next;
            cur->next = cur->next->next; 
            pre->next->next = temp;
        }
        return dummy->next;
    }
};







