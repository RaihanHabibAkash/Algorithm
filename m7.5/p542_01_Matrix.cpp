// Problem: 01 Matrix
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/01-matrix/
// Topics: 2D Grid, Multi source BFS
/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

class Solution {
public:
    int rows, cols;
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }
    void bfs(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0)
                    q.push({i,j});
                else mat[i][j] = -1;
            }

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;
                
                if(valid(ci, cj) && mat[ci][cj] == -1) {
                    mat[ci][cj] = mat[pi][pj] + 1;
                    q.push({ci,cj});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        bfs(mat);
        return mat;
    }
};