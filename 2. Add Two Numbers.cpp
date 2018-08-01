/* 2. Add Two Numbers 两个数字相加
 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order 
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 这道题需要建立一个新链表，然后把输入的两个链表从头往后，每两个相加，添加一个新节点到新链表后面，
   就是要处理下进位问题。还有,最高位的进位问题要最后特殊处理一下.*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int n1 = l1? l1->val : 0;
            int n2 = l2? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy->next;
    }
};







