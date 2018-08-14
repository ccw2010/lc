/*274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, 
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her 
N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.*/


/*这道题让我们求H指数，这个质数是用来衡量研究人员的学术水平的质数，定义为一个人的文章有n篇分别被引用了n次，
那么H指数就是n。而且wiki上直接给出了算法，可以按照如下方法确定某人的H指数：
1、将其发表的所有SCI论文按被引次数从高到低排序；
2、从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。
所得序号减一即为H指数*/

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int nPapers = citations.size();
        if (nPapers == 0) return 0;
        sort(citations.begin(), citations.end(), greater<int>());  
        for (int i = 0; i < nPapers; i++) {
            if (citations[i] <= i ) return i;
        }
        return nPapers;   
    }
};















