/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counts(26, 0);
        for (string word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.size();
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

