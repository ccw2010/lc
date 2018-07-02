/*373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
Return: [1,2],[1,4],[1,6]
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
Return: [1,1],[1,1]
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 
Return: [1,3],[2,3]

All possible pairs are returned from the sequence: [1,3],[2,3]
*/

/*这道题给了我们两个数组，让我们从每个数组中任意取出一个数字来组成不同的数字对，返回前K个和最小的数字对。
那么这道题有多种解法，我们首先来看brute force的解法，这种方法我们从0循环到数组的个数和k之间的较小值，
这样做的好处是如果k远小于数组个数时，我们不需要计算所有的数字对，而是最多计算k*k个数字对，然后将其都保存在res里，
这时候我们给res排序，用我们自定义的比较器，就是和的比较，然后把比k多出的数字对删掉即可*/

#include <vector>
#include <utility>
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> res;
        int n1 = min((int)nums1.size(), k);
        int n2 = min((int)nums2.size(), k);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        
        auto func = [](pair<int,int> &a, pair<int,int> &b){
            return a.first + a.second < b.first + b.second;
        };
        sort(res.begin(), res.end(), func);
        
        if (res.size() > k) {
            res.erase(res.begin() + k, res.end());
        }
        return res;
    }
};

/*我们也可以使用multimap来做，思路是我们将数组对之和作为key存入multimap中，利用其自动排序的机制，
这样我们就可以省去sort的步骤，最后把前k个存入res中即可*/

#include <map>
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int,int>> res;
        multimap<int, pair<int,int>> m;
        int n1 = min((int)nums1.size(), k);
        int n2 = min((int)nums2.size(), k);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        for (auto x : m) {
            res.push_back(x.second);
            if (--k <= 0) break;
        }
        return res;
    }
};






