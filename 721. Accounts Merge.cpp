/*721. Accounts Merge

Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0]
 is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is 
some email that is common to both accounts. Note that even if two accounts have the same name, they may 
belong to different people as people could have the same name. A person can have any number of accounts 
initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account 
is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned 
in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], 
	["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
	["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]

Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], 
['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] 
would still be accepted.

Note:
The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].*/

/*这个归组类的问题，最典型的就是岛屿问题(例如Number of Islands II)，很适合使用Union Find来做，LeetCode中有很多道可以使用
这个方法来做的题，比如Friend Circles，Graph Valid Tree，Number of Connected Components in an Undirected Graph，和
Redundant Connection等等。都是要用一个root数组，每个点开始初始化为不同的值，如果两个点属于相同的组，就将其中一个点的root值
赋值为另一个点的位置，这样只要是相同组里的两点，通过find函数得到相同的值。在这里，由于邮件是字符串不是数字，所以root可以用哈希
map来代替，我们还需要一个哈希映射owner，建立每个邮箱和其所有者姓名之前的映射，另外用一个哈希映射来建立用户和其所有的邮箱之间的
映射，也就是合并后的结果。

首先我们遍历每个账户和其中的所有邮箱，先将每个邮箱的root映射为其自身，然后将owner赋值为用户名。然后开始另一个循环，遍历每一个
账号，首先对帐号的第一个邮箱调用find函数，得到其父串p，然后遍历之后的邮箱，对每个遍历到的邮箱先调用find函数，将其父串的root值
赋值为p，这样做相当于将相同账号内的所有邮箱都链接起来了。我们下来要做的就是再次遍历每个账户内的所有邮箱，先对该邮箱调用find函数，
找到父串，然后将该邮箱加入该父串映射的集合汇总，这样就我们就完成了合并。最后只需要将集合转为字符串数组，加入结果res中，通过owner
映射找到父串的用户名，加入字符串数组的首位置*/


/* The key task here is to connect those emails, and this is a perfect use case for union find.
to group these emails, each group need to have a representative, or parent.
At the beginning, set each email as its own representative.
Emails in each account naturally belong to a same group, and should be joined by assigning to the 
same parent (let's use the parent of first email in that list);

Simple Example:

a b c // now b, c have parent a
d e f // now e, f have parent d
g a d // now abc, def all merged to group g

parents populated after parsing 1st account: a b c
a->a
b->a
c->a

parents populated after parsing 2nd account: d e f
d->d
e->d
f->d

parents populated after parsing 3rd account: g a d
g->g
a->g
d->g
*/


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, string> root;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> m;
        
        for (auto account : accounts) {
            string user = account[0];
            for (int i = 1; i < account.size(); ++i) {
                string email = account[i];
                root[email] = email;
                owner[email] = user;
            }
        }
        for (auto account : accounts) {
            string p = find(account[1], root);
            for (int i = 2; i < account.size(); i++) {
                string email = account[i];
                root[find(email, root)] = p;
            }
        }
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                m[find(email, root)].insert(email);
            }
        }
        for (auto x : m) {
            vector<string> v (x.second.begin(), x.second.end());
            v.insert(v.begin(), owner[x.first]);
            res.push_back(v);
        }
        return res;
    }
    
    string find(string s, unordered_map<string, string>& root) {
        if (root[s] == s) return s;
        else return find(root[s], root);
    }
};












