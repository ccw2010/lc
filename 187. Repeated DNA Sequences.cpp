/*187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res, seen;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string t = s.substr(i,10);
            if (seen.count(t)) res.insert(t);
            else seen.insert(t);
        }
        return vector<string>{res.begin(), res.end()};
    }
};










