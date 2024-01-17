/*
Title: Unique Number of Occurrences
URL: https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17


Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 
Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false

Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

 
Constraints:

	1 <= arr.length <= 1000
	-1000 <= arr[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        unordered_set<int> freq;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }

        for (auto& pair : mpp) {
            if (freq.find(pair.second) != freq.end()) {
                return false;
            }

            freq.insert(pair.second);
        }

        return true;
    }
};