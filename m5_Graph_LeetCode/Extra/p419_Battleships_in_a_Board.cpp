// Problem: Battleships in a Board
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/battleships-in-a-board/
// Topics: 2D Grid, DFS Components count

/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

Example 1:


Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
Example 2:

Input: board = [["."]]
Output: 0
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is either '.' or 'X'.
 

Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?
*/

class Solution {
public:
    int rows, cols;
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    bool vis[205][205];

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void dfs(vector<vector<char>>& board, int src_row, int src_col) {
        vis[src_row][src_col] = true;

        for(int i = 0; i < 4; i++) {
            int child_row = src_row + mv[i].first,
                child_col = src_col + mv[i].second;

            if(valid(child_row, child_col) && board[child_row][child_col] == 'X' && !vis[child_row][child_col])
                dfs(board, child_row, child_col);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        int cnt = 0;

        memset(vis, false, sizeof(vis));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] == 'X' && !vis[i][j]) {
                    cnt++;
                    dfs(board, i, j);
                }
        return cnt;
    }
};