/*138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to 
any node in the list or null.

Return a deep copy of the list. 
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/*这道链表的深度拷贝题的难点就在于如何处理随机指针的问题，由于每一个节点都有一个随机指针，这个指针可以为空，
也可以指向链表的任意一个节点，如果我们在每生成一个新节点给其随机指针赋值时，都要去遍历原链表的话，OJ上肯定会超时，
所以我们可以考虑用Hash map来缩短查找时间，第一遍遍历生成所有新节点时同时建立一个原节点和新节点的哈希表，第二遍给
随机指针赋值时，查找时间是常数级。*/

class Solution {
public:
    ListNode* copyRandomList(ListNode *head){
        if(!head) return NULL;
        ListNode *newHead = new ListNode(head->label);
        ListNode *src = head->next;
        ListNode *dst = newHead;
        map<ListNode*, ListNode*> m;
        m[head] = newHead;
        while(src){
            ListNode *copy = new ListNode(src->label);
            dst->next = copy;
            m[src] = copy;
            src = src->next;
            dst = dst->next;
        }
        dst = newHead;
        src = head;
        while(dst){
            dst->random = m[src->random];
            src = src->next;
            dst = dst->next;
        }
        return newHead;
    }
};


/*
Here's how the 2nd algorithm goes.
Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
Step 1:
Build the 2nd list by creating a new node for each node in 1st list. 
While doing so, set the next pointer of the new node to the random pointer 
of the corresponding node in the 1st list.  And set the random pointer of the 
1st list's node to the newly created node.
Step 2:
The new head is the node pointed to by the random pointer of the 1st list.
Step 3:
Fix the random pointers in the 2nd list: (Remember that l1->random is l2)
l2->random will be the node in 2nd list that corresponds to the node in the 
1st list that is pointed to by l2->next, 
Step 4:
Restore the random pointers of the 1st list and fix the next pointers of the 
2nd list. random pointer of the node in 1st list is the next pointer of the 
corresponding node in the 2nd list.  This is what we had done in the 
1st step and now we are reverting back. next pointer of the node in 
2nd list is the random pointer of the node in 1st list that is pointed to 
by the next pointer of the corresponding node in the 1st list.
Return the new head that we saved in step 2.
*/

class Solution {
public:
    ListNode* copyRandomList(ListNode *head) {
        ListNode *newHead, *l1, *l2;
        if (!head) return NULL;

        for (l1 = head; l1; l1 = l1->next) {
            l2 = new ListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }

        newHead = head->random;
        for (l1 = head; l1; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }

        for (l1 = head; l1; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : NULL;
        }

        return newHead;
    }
};
