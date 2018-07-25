/*146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following 
operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2); //capacity 

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*这道题让我们实现一个LRU缓存器，LRU是Least Recently Used的简写，就是最近最少使用的意思。那么这个缓存器主要有两个成员函数，
get和put，其中get函数是通过输入key来获得value，如果成功获得后，这对(key, value)升至缓存器中最常用的位置（顶部），如果key
不存在，则返回-1。而put函数是插入一对新的(key, value)，如果原缓存器中有该key，则需要先删除掉原有的，将新的插入到缓存器的顶部。
如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，也就是底部的值。具体实现时我们需要三个
私有变量，cap, l和m，其中cap是缓存器的容量大小，l是保存缓存器内容的列表，m是哈希表，保存关键值key和缓存器各项的迭代器之间映射，
方便我们以O(1)的时间内找到目标项。
然后再来看get和put如何实现，get相对简单些，我们在m中查找给定的key，如果存在则将此项移到顶部，并返回value，若不存在返回-1。
对于put，也是现在m中查找给定的key，如存在就删掉原有项，并在顶部插入新来项，然后判断是否溢出，若溢出则删掉底部项(最不常用项)*/


class LRUCache{
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        l_.splice(l_.begin(), l_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        if (it != m_.end()) l_.erase(it->second);
        l_.push_front(make_pair(key, value));
        m_[key] = l_.begin();
        if (m_.size() > cap_) {
            int k = l_.rbegin()->first;
            l_.pop_back();
            m_.erase(k);
        }
    }
    
private:
    int cap_;
    list<pair<int, int>> l_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};












