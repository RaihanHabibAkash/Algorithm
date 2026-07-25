// Problem: Number of Islands
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/number-of-islands/
// Topics: 2D Grid, Components Count using DFS

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'
*/

class Solution {
public:
    int rows, cols;
    bool visited[305][305];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int src_row, int src_col) {
        visited[src_row][src_col] = true;

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,
                child_col = src_col + mv[i].second;
            if(valid(child_row, child_col) && grid[child_row][child_col] == '1' && !visited[child_row][child_col])
                dfs(grid, child_row, child_col);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int lands = 0;
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j);
                    lands++;
                }
            }
        }
        return lands;
    }
};