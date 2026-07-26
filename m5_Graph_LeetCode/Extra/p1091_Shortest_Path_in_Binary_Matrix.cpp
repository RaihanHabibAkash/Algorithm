// Problem: Shortest Path in Binary Matrix
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Topics: 2D Grid BFS for shortest path

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

class Solution {
public:
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,1},{1,-1},{-1,-1}};
    int rows, cols;
    bool vis[105][105];
    int level[105][105];

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<int>>& grid, int src_row, int src_col) {
        queue<pair<int,int>> q;
        vis[src_row][src_col] = true;
        q.push({src_row, src_col});
        level[src_row][src_col] = 1;

        while(!q.empty()) {
            int par_row = q.front().first,
                par_col = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++) {
                int child_row = par_row + mv[i].first,
                    child_col = par_col + mv[i].second;
                
                if(valid(child_row, child_col) && grid[child_row][child_col] == 0 && !vis[child_row][child_col]) {
                    q.push({child_row, child_col});
                    level[child_row][child_col] = level[par_row][par_col] + 1;
                    vis[child_row][child_col] = true;
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        if(grid[0][0] == 0)
            bfs(grid, 0,0);

        return level[rows-1][cols-1];
    }
};