/* 686. Repeated String Match 

Given two strings A and B, find the minimum number of times A has to be repeated
such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it;
and B is not a substring of A repeated two times ("abcdabcd").

Note: The length of A and B will be between 1 and 10000.

用字符串B来匹配字符串A，问字符串A需要重复几次，如果无法匹配，则返回-1。那么B要能成为A的字符串，
那么A的长度肯定要大于等于B，所以当A的长度小于B的时候，我们可以先进行重复A，直到A的长度大于等于B，
并且累计次数cnt。那么此时我们用find来找，看B是否存在A中，如果存在直接返回cnt。如果不存在，我们再
加上一个A，再来找，这样可以处理这种情况A="abc", B="cab"，如果此时还找不到，说明无法匹配，返回-1*/


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size(), n2 = B.size();
        int count = 1;
        string t = A;
        while (t.size() < n2) {
            t += A;
            count++;
        }
        if (t.find(B) != string::npos) {
            return count;
        }else{        
            t += A;
            count++;
            if (t.find(B) != string::npos) return count;
            else return -1;
        }
    }
};







