// Problem: Number of Enclaves
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/number-of-enclaves/
// Topics: 2D Grid, BFS
/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1
*/

class Solution {
public:
    int rows, cols;
    bool vis[505][505];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    int cnt;

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<int>>& grid, int src_row, int src_col) {
        queue<pair<int,int>> q;
        q.push({src_row, src_col});
        vis[src_row][src_col] = true;

        while(!q.empty()) {
            int par_row = q.front().first,
                par_col = q.front().second;
            q.pop();
            
            cnt++;
            cout << par_row << " " << par_col << endl;
            
            for(int i = 0; i < 4; i++) {
                int child_row = par_row + mv[i].first,
                    child_col = par_col + mv[i].second;
                if(valid(child_row, child_col) && !vis[child_row][child_col] && grid[child_row][child_col] == 1) {
                    q.push({child_row, child_col});
                    vis[child_row][child_col] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(vis, false, sizeof(vis));

        cnt = 0; // hudai
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if((i == 0 || i == rows-1 || j == 0 || j == cols-1) && grid[i][j] == 1 && !vis[i][j])
                    bfs(grid, i, j);

        cnt = 0;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(!vis[i][j] && grid[i][j] == 1)
                    bfs(grid, i, j);

        return cnt;
    }
};