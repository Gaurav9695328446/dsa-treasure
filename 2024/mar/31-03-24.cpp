/*
URL: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2024-03-31

2444. Count Subarrays With Fixed Bounds

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

	The minimum value in the subarray is equal to minK.
	The maximum value in the subarray is equal to maxK.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 
Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

 
Constraints:

	2 <= nums.length <= 105
	1 <= nums[i], minK, maxK <= 106
*/

class Solution {
public:
       long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long res = 0, jbad = -1, jmin = -1, jmax = -1, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] < minK || A[i] > maxK) jbad = i;
            if (A[i] == minK) jmin = i;
            if (A[i] == maxK) jmax = i;
            res += max(0L, min(jmin, jmax) - jbad);
        }
        return res;
    }
};

