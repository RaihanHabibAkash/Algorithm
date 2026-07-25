// Problem: Number of Closed Islands
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/max-area-of-island/
// Topics: 2D Grid, Components max node & DFS

/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1
*/

class Solution {
public:
    int rows, cols, cnt;
    bool visited[55][55];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int src_row, int src_col) {
        visited[src_row][src_col] = true;
        cnt++;

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,
                child_col = src_col + mv[i].second;

            if(valid(child_row, child_col) && grid[child_row][child_col] == 1 && !visited[child_row][child_col])
                dfs(grid, child_row, child_col);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int mx = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    cnt = 0;
                    dfs(grid, i, j);

                    if(mx < cnt) mx = cnt;
                }
            }
        }

        return mx;
    }
};