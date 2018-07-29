/* 170. Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false 
*/

/*我们先来看用哈希表的解法，我们把每个数字和其出现的次数建立映射，然后我们遍历哈希表，对于每个值，我们先求出
此值和目标值之间的差值t，然后我们需要分两种情况来看，如果当前值不等于差值d，那么只要哈希表中有差值d就返回true，
或者是当差值d等于当前值时，如果此时哈希表的映射次数大于1，则表示哈希表中还有另一个和当前值相等的数字，二者相加
就是目标值*/

#include <unordered_map>
class TwoSum {
private:
    std::unordered_map<int,int> m_;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int n) {
        m_[n]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto n : m_){
            int d = value - n.first;
            if ((d != n.first && m_.count(d)) || (d == n.first && n.second > 1)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */







