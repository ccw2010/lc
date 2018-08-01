/*281. Zigzag Iterator

Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6] 

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,3,2,4,5,6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. 
If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].
*/

/*这道题让我们写一个之字形迭代器，跟之前那道Flatten 2D Vector有些类似，那道题是横向打印，这道题是纵向打印，
虽然方向不同，但是实现思路都是大同小异。我们可以直接在初始化的时候就两个数组按照之字形的顺序存入另一个一位数组中了，
那么我们就按顺序打印新数组中的值即可*/

class ZigzagIterator {
private:
    vector<int> v_;
    int i_;

public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int n = max(n1, n2);
        for (int i_ = 0; i_ < n; i_++) {
            if (i_ < n1) v_.push_back(v1[i_]);
            if (i_ < n2) v_.push_back(v2[i_]);
        }
    }
    int next() {
        return v_[i_++];
    }
    bool hasNext() {
        return i_ < v_.size();
    }
};
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


/*由于题目中的Follow up让我们考虑将输入换成k个数组的情况，那么上面的解法显然就不适用了，需要一种通解。
我们可以采用queue加iterator的方法，用一个queue里面保存iterator的pair，在初始化的时候，有几个数组就
生成几个pair放到queue中，每个pair保存该数组的首位置和尾位置的iterator，在next()函数中，我们取出queue
队首的一个pair，如果当前的iterator不等于end()，我们将其下一个位置的iterator和end存入队尾，然后返回
当前位置的值。在hasNext()函数中，我们只需要看queue是否为空即可*/

class ZigzagIterator {
private:
    typedef vector<int>::iterator vItr;
    queue<pair<vItr, vItr>> q;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if (!v2.empty()) {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }
    int next() {
        auto it = q.front().first;
        auto end = q.front().second;
        q.pop();
        if (it + 1 != end) {
            q.push(make_pair(it + 1, end));
        }
        return *it;
    }
    bool hasNext() {
        return !q.empty();
    }
};









