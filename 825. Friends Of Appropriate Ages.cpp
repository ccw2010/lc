/*825. Friends Of Appropriate Ages

Some people will make friend requests. The list of their ages is given and ages[i] 
is the age of the ith person. 

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

    age[B] <= 0.5 * age[A] + 7
    age[B] > age[A]
    age[B] > 100 && age[A] < 100

Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request 
themselves.

How many total friend requests are made?

Example 1:
Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:
Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:
Input: [20,30,100,110,120]
Output: 
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.

Notes:
1 <= ages.length <= 20000.
1 <= ages[i] <= 120.*/

/*Since the age range is limited to [1..120], we can count number of people of each age and store 
in the array. Then we can use that array to count friend requests:

    People younger than 15 cannot make requests due to the first rule.
    From the age of 15, people can make requests to the same age: a[i] * a[i - 1] requests.
    People can make requests to younger people older than 0.5 * i + 7: a[j] * a[i] requests.
        The third rule is redundant as the condition is already covered by the second rule.

The complexity is O(n) as we need to count ages in the input array. Counting requests is O(1) as it 
always takes 2862 operations precisely.*/


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int m[121] = {}, res = 0;
        for (auto age : ages) m[age]++;
        for (auto i = 15; i <= 120; i++){
            for (int j = 0.5 * i + 8; j <= i; j++) {
            	res += m[j] * (m[i] - (i == j));
            }
        }
        return res;
    }
};





