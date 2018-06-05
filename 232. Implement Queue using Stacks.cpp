/*232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.
    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Example:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, 
size, and is empty operations are valid. Depending on your language, stack may not be supported natively. 
You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard 
operations of a stack. You may assume that all operations are valid (for example, no pop or peek operations
 will be called on an empty queue). */

/*这个方法使用了两个栈_new和_old，其中新进栈的都先缓存在_new中，入栈要pop和peek的时候，
才将_new中所有元素移到_old中操作，提高了效率*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    void shift(){
        if(_new.empty()){
            while(!_old.empty()){
                _new.push(_old.top());
                _old.pop();
            }
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _old.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shift();
        int res;
        if(!_new.empty())
            res = _new.top();
            _new.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        shift();
        if(!_new.empty())
            return _new.top();
        return 0;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _new.empty() && _old.empty();
    }
    
private:
    stack<int> _old, _new;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */