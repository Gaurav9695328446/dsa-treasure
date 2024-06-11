/*
URL: https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10

1051. Height Checker

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].

 
Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

Example 2:

Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.

Example 3:

Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.

 
Constraints:

	1 <= heights.length <= 100
	1 <= heights[i] <= 100
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        // counting sort
        char freq[101]={0};
        for(char x: sorted) freq[x]++;
        int cnt=0;
        for (int x=1; x<=100; x++){
            int f=freq[x];
            vector<char> f_x(f, x);
            copy(begin(f_x), end(f_x), sorted.begin()+cnt);
            cnt+=f;
        }
        //end of count sort

        int n=heights.size(), ans=0;
        for(int i=0; i<n; i++)
            ans+=(heights[i]!=sorted[i]);
        return ans;      
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();