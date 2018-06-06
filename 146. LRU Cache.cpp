/*这道题是一个数据结构设计题，是很经典的一道题，可以好好看看。

这道题要求设计实现LRU cache的数据结构，实现set和get功能。学习过操作系统的都应该知道，cache作为缓存可以帮助快速存取数据，
但是确定是容量较小。这道题要求实现的cache类型是LRU，LRU的基本思想就是“最近用到的数据被重用的概率比较早用到的大的多”
，是一种更加高效的cache类型。

解决这道题的方法是：双向链表+HashMap。

为了能够快速删除最久没有访问的数据项和插入最新的数据项，我们将双向链表连接Cache中的数据项，并且保证链表维持数据项从最近
访问到最旧访问的顺序。 每次数据项被查询到时，都将此数据项移动到链表头部（O(1)的时间复杂度）。这样，在进行过多次查找操作后，
最近被使用过的内容就向链表的头移动，而没 有被使用的内容就向链表的后面移动。当需要替换时，链表最后的位置就是最近最少被使用的
数据项，我们只需要将最新的数据项放在链表头部，当Cache满 时，淘汰链表最后的位置就是了。 

 注： 对于双向链表的使用，基于两个考虑。
    1. 首先是Cache中块的命中可能是随机的，和Load进来的顺序无关。

    2. 其次，双向链表插入、删除很快，可以灵活的调整相互间的次序，时间复杂度为O(1)。

解决了LRU的特性，现在考虑下算法的时间复杂度。为了能减少整个数据结构的时间复杂度，就要减少查找的时间复杂度，所以这里利用
HashMap来做，这样时间苏咋读就是O(1)。

所以对于本题来说：

get(key): 如果cache中不存在要get的值，返回-1；如果cache中存在要找的值，返回其值并将其在原链表中删除，然后将其作为头结点。

set(key,value)：当要set的key值已经存在，就更新其value， 将其在原链表中删除，然后将其作为头结点；当药set的key值不存在，
就新建一个node，如果当前len<capacity,就将其加入hashmap中，并将其作为头结点，更新len长度，否则，删除链表最后一个node，
再将其放入hashmap并作为头结点，但len不更新。

原则就是：对链表有访问，就要更新链表顺序。 */


/*这道题让我们实现一个LRU缓存器，LRU是Least Recently Used的简写，就是最近最少使用的意思。那么这个缓存器主要有两个成员函数，
get和put，其中get函数是通过输入key来获得value，如果成功获得后，这对(key, value)升至缓存器中最常用的位置（顶部），如果key
不存在，则返回-1。而put函数是插入一对新的(key, value)，如果原缓存器中有该key，则需要先删除掉原有的，将新的插入到缓存器的顶部。
如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，也就是底部的值。具体实现时我们需要三个
私有变量，cap, l和m，其中cap是缓存器的容量大小，l是保存缓存器内容的列表，m是哈希表，保存关键值key和缓存器各项的迭代器之间映射，
方便我们以O(1)的时间内找到目标项。

然后我们再来看get和put如何实现，get相对简单些，我们在m中查找给定的key，如果存在则将此项移到顶部，并返回value，若不存在返回-1。
对于put，我们也是现在m中查找给定的key，如果存在就删掉原有项，并在顶部插入新来项，然后判断是否溢出，若溢出则删掉底部项(最不常用项)*/


class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};







