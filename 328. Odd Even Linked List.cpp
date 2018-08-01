/* 328. Odd Even Linked List 

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here 
we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time 
complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/* 这道题给了我们一个链表，让我们分开奇偶节点，所有奇节点在前，偶节点在后。我们可以使用两个指针来做，
pre指向奇节点，cur指向偶节点，然后把偶节点cur后面的那个奇节点提前到pre的后面，然后pre和cur各自
前进一步，此时cur又指向偶节点，pre指向当前奇节点的末尾，以此类推直至把所有的偶节点都提前了即可 */

class Solution{
public:
    ListNode* oddEvenList(ListNode *head){
        if (!head || !head->next) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur && cur->next){
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};








