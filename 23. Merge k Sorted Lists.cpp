/* 23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/* The second function is from Merge Two Sorted Lists.

The basic idea is really simple. We can merge first two lists and then push it back. 
Keep doing this until there is only one list left in vector. Actually, we can regard 
this as an iterative divide-and-conquer solution.*/

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
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return NULL;
    
        while (lists.size() > 1){
            ListNode *merged = mergeTwoLists(lists[0], lists[1]);
            lists.push_back(merged);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};



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
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return NULL;
        while (lists.size() > 1){
            ListNode *merged = merge2List(lists[0], lists[1]);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(merged);
        }
        return lists[0];
    }
    
    ListNode* merge2List(ListNode *l1, ListNode *l2){
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1? l1 : l2;
        return dummy->next;
    }
};







