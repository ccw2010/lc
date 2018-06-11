/*251. Flatten 2D Vector

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
 

By calling next repeatedly until hasNext returns false, the order of elements returned 
by next should be: [1,2,3,4,5,6].

Hint:

How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. 
Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.*/

/*这道题让我们压平一个二维向量数组，并且实现一个iterator的功能，包括next和hasNext函数，那么最简单的方法就是
将二维数组按顺序先存入到一个一维数组里，然后此时只要维护一个变量i来记录当前遍历到的位置，hasNext函数看当前坐标
是否小于元素总数，next函数即为取出当前位置元素，坐标后移一位 */ 


class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto v : vec2d) {
            nums.insert(nums.end(), v.begin(), v.end());
        }    
    }
    
    int next() {
        return nums[i++];
    }
    
    bool hasNext() {
        return i < nums.size();
    }
    
private:
    vector<int> nums;
    int i = 0;
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */






