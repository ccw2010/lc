/* 294. Flip Game 
 
You are playing the following Flip Game with your friend: Given a string that contains only these 
two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The 
game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the 
middle "++" to become "+--+".

Follow up: Derive your algorithm's runtime complexity. */
 
/* 这道题让我们判断先手的玩家是否能赢，那么我们可以穷举所有的情况，用回溯法来解题，也是从第二个字母开始遍历整个字符串，
如果当前字母和之前那个字母都是+，那么我们递归调用将这两个位置变为--的字符串，如果返回false，说明当前玩家可以赢，结束
循环返回false */
 
class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        for (int i = 0; i < n-1; i++) {
            if (s.substr(i,2) == "++") {
                string flipped = s.substr(0,i) + "--" + s.substr(i+2);
                if (!canWin(flipped)) return true;
            }
        }
        return false;
    }
};








