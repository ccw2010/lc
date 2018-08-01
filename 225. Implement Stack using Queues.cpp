/*225. Implement Stack using Queues 

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Notes:
You may assume that all operations are valid (for example, no pop or top operations will be called on 
an empty stack).Depending on your language, queue may not be supported natively. You may simulate a queue 
by using a list or deque (double-ended queue), as long as you use only standard operations of a queue -- 
which means only push to back, pop from front, size, and is empty operations are valid.
*/
 
/*这道题让我们用队列来实现栈，队列和栈作为两种很重要的数据结构，它们最显著的区别就是，队列是先进先出，而栈是先进后出。
题目要求中又给定了限制条件只能用queue的最基本的操作，像back()这样的操作是禁止使用的。那么怎么样才能让先进先出的特性
模拟出先进后出呢，这里可以参见232.Implement Queue using Stacks 用栈来实现队列，只要实现对了push函数，后面三个直接
调用队列的函数即可。这种方法的原理就是每次把新加入的数插到前头，这样队列保存的顺序和栈的顺序是相反的，它们的取出方式也是
反的，那么反反得正，就是我们需要的顺序了。我们需要一个辅助队列tmp，把s的元素也逆着顺序存入tmp中，此时加入新元素x，再把
tmp中的元素存回来，这样就是我们要的顺序了，其他三个操作也就直接调用队列的操作即可*/

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */












