// Problem: Maximum Number of Fish in a Grid
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
// Topics: 2D Grid & DFS

/*
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

Example 1:


Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
*/

class Solution {
public:
    int rows, cols, cnt;
    bool visited[15][15];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid, int src_row, int src_col) {
        visited[src_row][src_col] = true;
        cnt += grid[src_row][src_col];

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,
                child_col = src_col + mv[i].second;
            if(valid(child_row, child_col) && grid[child_row][child_col] > 0 && !visited[child_row][child_col])
                dfs(grid, child_row, child_col);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int mx = 0;
        rows = grid.size();
        cols = grid[0].size();

        memset(visited, false, sizeof(visited));

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] > 0 && !visited[i][j]) {
                    cnt = 0;
                    dfs(grid, i, j);
                    if(mx < cnt) mx = cnt;
                }
        return mx;
    }
};