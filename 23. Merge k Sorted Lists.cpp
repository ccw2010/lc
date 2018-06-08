/*23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]

Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
The second function is from Merge Two Sorted Lists.

The basic idea is really simple. We can merge first two lists and then push it back. 
Keep doing this until there is only one list left in vector. Actually, we can regard 
this as an iterative divide-and-conquer solution.*/

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
        if(lists.empty()) return nullptr;
    
        while(lists.size() > 1){
            ListNode* mergedList = merge(lists[0], lists[1]);
            lists.push_back(mergedList);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode *merge(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val <= l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};






