/*432. All O`one Data Structure

Implement a data structure supporting the following operations:

- Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed 
  to be a non-empty string.
- Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. 
  If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
- GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
- GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".

Challenge: Perform all these in O(1) time complexity. */


/*这道题让我们实现一个全是O(1)复杂度的数据结构，包括了增加key，减少key，获取最大key，获取最小key，这几个函数。
由于需要常数级的时间复杂度，我们首先第一反应就是要用哈希表来做，不仅如此，我们肯定还需要用list来保存所有的key，
那么哈希表就是建立key和list中位置迭代器之间的映射，这不由得令人想到了之前那道LRU Cache，也是用了类似的方法来解，
但是感觉此题还要更加复杂一些。由于每个key还要对应一个次数，所以list中不能只放key，而且相同的次数可能会对应多个key值，
所以我们用unordered_set来保存次数相同的所有key值，我们建立一个Bucket的结构体来保存次数val，和保存key值的集合keys。
解题思路是，我们建立一个次数分层的结构，次数多的在顶层，每一层放相同次数的key值，例如下面这个例子：

"A": 4, "B": 4, "C": 2, "D": 1

那么用我们设计的结构保存出来就是：

row0: val = 4, keys = {"A", "B"}
row1: val = 2, keys = {"C"}
row2: val = 1, keys = {"D"}

好，我们现在来分析如何实现inc函数，我们来想，如果我们插入一个新的key，跟我们插入一个已经存在的key，情况是完全不一样的，
那么我们就需要分情况来讨论:

- 如果我们插入一个新的key，那么由于该key没有出现过，所以加入后次数一定为1，那么就有两种情况了，如果list中没有val为1的这
一行，那么我们需要插入该行，如果已经有了val为1的这行，我们直接将key加入集合keys中即可。

- 如果我们插入了一个已存在的key，那么由于个数增加了1个，所以该key值肯定不能在当前行继续待下去了，要往上升职啊，那么这里
就有两种情况了，如果该key要升职到的那行不存在，我们需要手动添加那一行；如果那一行存在，我们之间将key加入集合keys中，记得
都要将原来行中的key值删掉。

下面我们再来看dec函数如何实现，其实理解了上面的inc函数，那么dec函数也就没什么难度了：

- 如果我们要删除的key不存在，那么直接返回即可。

- 如果我们要删除的key存在，那么我们看其val值是否为1，如果为1的话，那么直接在keys中删除该key即可，然后还需要判断如果该key
是集合中的唯一一个，那么该行也需要删除。如果key的次数val不为1的话，我们要考虑降级问题，跟之前的升职很类似，如果要降级的行
不存在，我们手动添加上，如果存在，则直接将key值添加到keys集合中即可。

当我们搞懂了inc和dec的实现方法，那么getMaxKey()和getMinKey()简直就是福利啊，不要太简单啊，直接返回首层和尾层的key值即可*/


class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m.count(key)) {
            if (buckets.empty() || buckets.back().val != 1) {
                auto newBucket = buckets.insert(buckets.end(), {1, {key}});
                m[key] = newBucket;
            } else {
                auto newBucket = --buckets.end();
                newBucket->keys.insert(key);
                m[key] = newBucket;
            }
        } else {
            auto curBucket = m[key], lastBucket = (--m[key]);
            if (lastBucket == buckets.end() || lastBucket->val != curBucket->val + 1) {
                auto newBucket = buckets.insert(curBucket, {curBucket->val + 1, {key}});
                m[key] = newBucket;
            } else {
                lastBucket->keys.insert(key);
                m[key] = lastBucket;
            }
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return;
        auto curBucket = m[key];
        if (curBucket->val == 1) {
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) buckets.erase(curBucket);
            m.erase(key);
            return;
        }
        auto nextBucket = ++m[key];
        if (nextBucket == buckets.end() || nextBucket->val != curBucket->val - 1) {
            auto newBucket = buckets.insert(nextBucket, {curBucket->val - 1, {key}});
            m[key] = newBucket;
        } else {
            nextBucket->keys.insert(key);
            m[key] = nextBucket;
        }
        curBucket->keys.erase(key);
        if (curBucket->keys.empty()) buckets.erase(curBucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
private:
    struct Bucket { 
        int val; 
        unordered_set<string> keys; 
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> m;
};



/*解法2: 用三个map实现 */
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
     
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!m1.count(key) ) {
            //new key
            m1.insert(make_pair(key, 1));
            auto p = m2.insert(make_pair(1, key));
            m3.insert(make_pair(key, p));
        } else {
            //exist key
            int oldVal = m1[key];
            m1[key]++;
            //find old key in map2
            auto oldValInMap2it = m3[key];
            m2.erase(oldValInMap2it);
            auto p = m2.insert(make_pair(oldVal + 1, key));
            m3.erase(key);
            m3.insert(make_pair(key, p));
        }
    }
     
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m1.count(key)){
            //find the key
            int oldVal = m1[key];
            if(oldVal == 1) {
                //remove it from map1 map2 and map3
                m1.erase(key);
                auto oldValInMap2it = m3[key];
                m2.erase(oldValInMap2it);
                m3.erase(key);
            }else {
                //decrease the value
                //exist key
                m1[key]--;
                //find old key in map2
                auto oldValInMap2it = m3[key];
                m2.erase(oldValInMap2it);
                auto p = m2.insert(make_pair(oldVal - 1, key));
                m3.erase(key);
                m3.insert(make_pair(key, p));
            }
        }
    }
     
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(m2.size() == 0) return "";
        else return (m2.rbegin())->second;   
    }
     
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(m2.size() == 0) return "";
        else return (m2.begin())->second;         
    }
     
private:
    unordered_map<string, int> m1;   // key to value map
    typedef multimap<int, string>::iterator m2it; 
    multimap<int, string> m2;        // value to key map
    unordered_map<string, m2it> m3;  // key to it in map2
};
 
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */





