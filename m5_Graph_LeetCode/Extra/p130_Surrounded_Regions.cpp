// Problem: Surrounded Regions
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/surrounded-regions/
// Topics: 2D Grid DFS only in side rows & cols

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'
*/

class Solution {
public:
    int rows, cols;
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    bool visited[205][205];

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<char>>& board, int src_row, int src_col) {
        visited[src_row][src_col] = true;

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,
                child_col = src_col + mv[i].second;
            if(valid(child_row, child_col) && board[child_row][child_col] == 'O' && !visited[child_row][child_col])
                dfs(board, child_row, child_col);
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        memset(visited, false, sizeof(visited));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] == 'O' && !visited[i][j] && (i == 0 || i == rows-1 || j == 0 || j == cols-1))
                    dfs(board, i, j);

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
    }
};