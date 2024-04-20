/*
URL: https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20

1992. Find All Groups of Farmland

You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

 
Example 1:

Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

Example 2:

Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].

Example 3:

Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.

 
Constraints:

	m == land.length
	n == land[i].length
	1 <= m, n <= 300
	land consists of only 0's and 1's.
	Groups of farmland are rectangular in shape.
*/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        vector<vector<int>> result;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        set<pair<int, int>> visited;
        
        auto bfs = [&](int start_row, int start_col) -> vector<int> {
            queue<pair<int, int>> q;
            q.push({start_row, start_col});
            visited.insert({start_row, start_col});
            int min_row = start_row, min_col = start_col, max_row = start_row, max_col = start_col;
            
            while (!q.empty()) {
                auto [cur_row, cur_col] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int new_row = cur_row + dr;
                    int new_col = cur_col + dc;
                    
                    if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && visited.find({new_row, new_col}) == visited.end() && land[new_row][new_col] == 1) {
                        visited.insert({new_row, new_col});
                        q.push({new_row, new_col});
                        min_row = min(min_row, new_row);
                        min_col = min(min_col, new_col);
                        max_row = max(max_row, new_row);
                        max_col = max(max_col, new_col);
                    }
                }
            }
            
            return {min_row, min_col, max_row, max_col};
        };
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                    vector<int> farmland = bfs(i, j);
                    result.push_back(farmland);
                }
            }
        }
        
        return result;
    }
};