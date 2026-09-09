// Problem: Shortest Bridge
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/shortest-bridge/
// Topics: 2D Grid, DFS & BFS (Multi source)
/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/

class Solution {
public:
    int n;
    int lvl[105][105];
    bool vis[105][105];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int si, int sj) {
        vis[si][sj] = true;

        for(int i = 0; i < 4; i++) {
            int ci = si + mv[i].first,
                cj = sj + mv[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
                dfs(grid, ci, cj);
        }
    }

    int bfs(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(vis[i][j] && grid[i][j] == 1) {
                    q.push({i, j});
                    lvl[i][j] = 0;
                }

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;
                if(valid(ci, cj) && !vis[ci][cj]) {
                    q.push({ci, cj});
                    lvl[ci][cj] = lvl[pi][pj] + 1;
                    vis[ci][cj] = true;

                    // Checking
                    if(grid[ci][cj] == 1)
                        return lvl[ci][cj] - 1;
                }
            }
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        memset(vis, false, sizeof(vis));
        memset(lvl, -1, sizeof(lvl));
        
        bool flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        return bfs(grid);
    }
};