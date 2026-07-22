// Problem: Number of Closed Islands
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/number-of-closed-islands/
// Topics: 2D Grid, DFS with Grid indexing logic
/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

class Solution {
public:
    int rows, cols;
    bool flag;
    vector<pair<int,int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool visited[105][105];

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int si, int sj) {
        visited[si][sj] = true;
        if(si == 0 || si == rows-1 || sj == 0 || sj == cols-1)
            flag = true;

        for(int i = 0; i < 4; i++) {
            int ci = si + mv[i].first,
                cj = sj + mv[i].second;
            if(valid(ci, cj) && grid[ci][cj] == 0 && !visited[ci][cj])
                dfs(grid, ci, cj);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        memset(visited, false, sizeof(visited));

        int cnt = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                flag = false;
                if(grid[i][j] == 0 && !visited[i][j]) {
                    dfs(grid, i, j);
                    if(!flag) cnt++;
                }
            }
        }

        return cnt;
    }
};