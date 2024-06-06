/*
URL: https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06

846. Hand of Straights

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 
Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 
Constraints:

	1 <= hand.length <= 104
	0 <= hand[i] <= 109
	1 <= groupSize <= hand.length

 
Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // Step 1: Check if grouping is possible
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Step 2: Count the occurrences of each card
        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Step 3: Sort the unique card values
        std::vector<int> sortedKeys;
        for (auto& pair : count) {
            sortedKeys.push_back(pair.first);
        }
        std::sort(sortedKeys.begin(), sortedKeys.end());

        // Step 4: Form consecutive groups
        for (int key : sortedKeys) {
            if (count[key] > 0) {  // If this card is still available
                int startCount = count[key];
                // Check and form a group starting from `key`
                for (int i = key; i < key + groupSize; i++) {
                    if (count[i] < startCount) {
                        return false;
                    }
                    count[i] -= startCount;
                }
            }
        }

        // Step 5: Return true if all groups are formed successfully
        return true;
    }
};