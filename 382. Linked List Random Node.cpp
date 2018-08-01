/*382. Linked List Random Node

Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently 
without using extra space?

Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/

/*这道题给了我们一个链表，让我们随机返回一个节点，那么最直接的方法就是先统计出链表的长度，然后根据长度随机生成一个位置，
然后从开头遍历到这个位置即可*/

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        ListNode *cur = head;
        head_ = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % len;
        ListNode *cur = head_;
        while (n) {
            n--;
            cur = cur->next;
        }
        return cur->val;
    }
private:
    int len;
    ListNode *head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

/*Follow up中说链表可能很长，我们没法提前知道长度，这里用到了著名了Reservoir Sampling的思路，由于限定了head一定存在，
所以我们先让返回值res等于head的节点值，然后让cur指向head的下一个节点，定义一个变量i，初始化为2，若cur不为空我们开始循环，
我们在[0, i-1]中取一个随机数，如果取出来0，那么我们更新res为当前的cur的节点值，然后此时i自增一，cur指向其下一个位置，
这里其实相当于我们维护了一个大小为1的水塘，然后我们随机数生成为0的话，我们交换水塘中的值和当前遍历到底值，这样可以保证每个
数字的概率相等*/

class Solution {
private:
    ListNode *head_;
    
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, 
         so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head_->val;
        int i = 2;
        ListNode *cur = head_->next;
        while (cur) {
            int j = rand() % i;
            if (j==0) res = cur->val;
            i++;
            cur = cur->next;
        }
        return res;
    }
};















