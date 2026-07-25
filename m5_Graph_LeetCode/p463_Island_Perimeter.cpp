// Problem: Island Perimeter
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/island-perimeter/
// Topics: 2D Grid, DFS

/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid
*/


class Solution {
public:
    int rows, cols, cnt = 0;
    bool visited[105][105];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            cnt++;
            return false;
        }
        return true;
    }

    void bfs(vector<vector<int>>& grid, int src_row, int src_col) {
        queue<pair<int,int>> q;
        q.push({src_row, src_col});
        visited[src_row][src_col] = true;

        while(!q.empty()) {
            int par_row = q.front().first,
                par_col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int child_row = par_row + mv[i].first,
                    child_col = par_col + mv[i].second;
                
                if(valid(grid, child_row, child_col) && !visited[child_row][child_col]) {
                    q.push({child_row, child_col});
                    visited[child_row][child_col] = true;
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        memset(visited, false, sizeof(visited));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 1 && !visited[i][j])
                    bfs(grid, i, j);

        return cnt;
    }
};