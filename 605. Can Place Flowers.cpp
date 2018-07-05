/*605. Can Place Flowers
Suppose you have a long flowerbed in which some of the plots are planted and some are not. 
However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), 
and a number k, return if k new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], k = 1
Output: True

Example 2:
Input: flowerbed = [1,0,0,0,1], k = 2
Output: False*/

/* 这道题给了我们一个01数组，其中1表示已经放了花，0表示可以放花的位置，但是有个限制条件是不能有相邻的花。那么我们来看一些简单
的例子，如果有3个连续的零，000，能放几盆花呢，其实是要取决约左右的位置的，如果是10001，那么只能放1盆，如果左右是边界的花，那
么就能放两盆，101，所以如果我们想通过计算连续0的个数，然后直接算出能放花的个数，就必须要对边界进行处理，处理方法是首位置前面
加上个0，最后面再加上个0。然后就三个三个的来遍历，如果找到了三个连续的0，那么f[i]==1，n自减1，最后看k是否小于等于0 */

class Solution {
public:
    bool canPlaceFlowers(vector<int> &f, int k) {
        if (f.empty()) return false;
        int n = f.size();
        f.insert(f.begin(), 0);
        f.push_back(0);
        for(int i=1; i<n-1; i++){
            if (k==0) return true;
            if (f[i-1] + f[i] + f[i+1] == 0){
                f[i] = 1;
                k--;
            } 
        }
        return k <= 0;
    }
};