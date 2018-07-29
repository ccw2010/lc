/*379. Design Phone Directory

Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.

Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/


/*这道题让我们设计一个电话目录管理系统，可以分配电话号码，查询某一个号码是否已经被使用，释放一个号码，
需要注意的是，之前释放的号码下一次应该被优先分配。这题对C++解法的时间要求非常苛刻，尝试了好几种用set，或者stack/queue，
或者使用vector的push_back等等，都TLE了，终于找到了一种可以通过OJ的解法。这里用两个一维数组freeList和isFree，分别来保存
被回收的号码和某个号码的使用状态，还有变量maxNum表示最大数字，next表示下一个可以分配的数字，index表示recycle数组中可以被
重新分配的数字的位置，然后在get函数中，没法分配的情况是，当next等于maxNum并且index小于等于0，此时返回-1。否则我们先看
recycle里有没有数字，有的话先分配recycle里的数字，没有的话再分配next。记得更新相对应的isFree中的使用状态*/

class PhoneDirectory {
private:
    int maxNum_, next_, index_;
    vector<int> recycle_, isFree_;
    
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxNum_ = maxNumbers;
        next_ = index_ = 0;
        recycle_.resize(maxNum_);
        isFree_.resize(maxNum_, 1);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next_ == maxNum_ && index_ <= 0) return -1;
        if (index_ > 0) {
            index_--;
            int t = recycle_[index_];
            isFree_[t] = 0;
            return t;
        }
        isFree_[next_] = false;
        return next_++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < maxNum_ && isFree_[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < maxNum_ && !isFree_[number]) {
            recycle_[index_] = number;
            index_++;
            isFree_[number] = 1;
        }
    }
};











