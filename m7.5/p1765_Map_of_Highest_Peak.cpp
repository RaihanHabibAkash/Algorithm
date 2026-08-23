// Problem: Map of Highest Peak
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/map-of-highest-peak/
// Topics: Multi source BFS in 2D grid

/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell
*/

class Solution {
public:
    int rows, cols;
    bool vis[1005][1005];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;

        // All the water is pushing in the queue
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(!vis[i][j] && isWater[i][j] == 1) {
                    vis[i][j] = true;
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
        
        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;
                
                if(valid(ci, cj) && !vis[ci][cj]) {
                    vis[ci][cj] = true;
                    q.push({ci, cj});
                    isWater[ci][cj] = isWater[pi][pj] + 1;
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        rows = isWater.size();
        cols = isWater[0].size();
        memset(vis, false, sizeof(vis));

        bfs(isWater);

        return isWater;
    }
};