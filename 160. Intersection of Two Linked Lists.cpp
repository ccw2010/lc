/*160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if (!head1 || !head2) return NULL;
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        int d = abs(len1-len2);      
        if (len1 < len2){
            while (d--) { head2 = head2->next; }
        } else{
            while (d--) { head1 = head1->next; }
        }      
        while (head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }   
        return head1;
    }
    
    int getLength(ListNode *head){
        int len = 0;
        while (head){
            len++;
            head = head->next;
        }
        return len;
    }
};







