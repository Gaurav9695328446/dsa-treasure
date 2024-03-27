/*
URL: https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 
Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

 
Constraints:

	1 <= nums.length <= 3 * 104
	1 <= nums[i] <= 1000
	0 <= k <= 106
*/

class Solution {
public:
   int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		
		// as all numbers in the array are positive
        if(k <= 1) return 0;
        
		// initialize some vars
        int prod = 1, res = 0, left = 0;
        
		// traversing through each window
        for(int right = 0; right < nums.size(); right++) {
			
			// store the product of elements which we see new in window 
            prod *= nums[right];
    
			// if product is greater than the given k 
			// then slide the window by doing left++ and dividing prod by nums[left] 
            while(prod >= k) {
                prod /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};