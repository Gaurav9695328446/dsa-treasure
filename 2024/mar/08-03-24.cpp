/*
URL: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

3005. Count Elements With Maximum Frequency

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

 
Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.

Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.

 
Constraints:

	1 <= nums.length <= 100
	1 <= nums[i] <= 100
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int, int> freqCounter;
        for (int num : nums) {
            freqCounter[num]++;
        }

        int maxFrequency = 0;
        for (const auto& entry : freqCounter) {
            maxFrequency = std::max(maxFrequency, entry.second);
        }

        int maxFreqElements = 0;
        for (const auto& entry : freqCounter) {
            if (entry.second == maxFrequency) {
                maxFreqElements++;
            }
        }

        int totalFrequency = maxFrequency * maxFreqElements;

        return totalFrequency;
    }
};