#include<bits/stdc++.h>
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //brute force O(n2)
        //         int ans = -1;
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i + 1; j < s.size(); j++) {
        //         if (s[i] == s[j]) {
        //             ans = max(ans, (j - i) - 1);
        //         }
        //     }
        // }

        // return ans;

        unordered_map<char, int> firstIndex;
        int ans = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[s[i]] - 1);
            } else {
                firstIndex[s[i]] = i;
            }
        }

        return ans;
    }
};

