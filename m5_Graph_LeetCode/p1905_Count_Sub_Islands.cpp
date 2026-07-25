// Problem: Count Sub Islands
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/count-sub-islands/
// Topics: 2 2D Grid, Componentes checking & DFS

/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1
*/


class Solution {
public:
    bool visited[505][505];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    int rows, cols;
    bool flag;
    
    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int src_row, int src_col) {
        visited[src_row][src_col] = true;
        if(grid1[src_row][src_col] == 0) flag = false;

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,  
                child_col = src_col + mv[i].second;
            if(valid(child_row, child_col) && grid2[child_row][child_col] == 1 && !visited[child_row][child_col])
                dfs(grid1, grid2, child_row, child_col);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid2.size();
        cols = grid2[0].size();
        int sub_islands = 0;

        memset(visited, false, sizeof(visited));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid2[i][j] == 1 && !visited[i][j]) {
                    flag = true;
                    dfs(grid1, grid2, i, j);
                    if(flag) sub_islands++; 
                }

        return sub_islands;
    }
};