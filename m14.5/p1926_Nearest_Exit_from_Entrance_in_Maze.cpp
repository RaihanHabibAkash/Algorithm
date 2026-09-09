// Problem: Nearest Exit from Entrance in Maze
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Topics: 2D Grid, BFS
/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

Example 1:


Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:


Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:


Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
 

Constraints:

maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
*/
class Solution {
public:
    int di, dj;
    bool vis[105][105];
    int lvl[105][105];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= di || j < 0 || j >= dj)
            return false;
        return true;
    }

    int bfs(vector<vector<char>>& maze, int si, int sj) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        vis[si][sj] = true;
        lvl[si][sj] = 0;

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();
            cout << pi << " " << pj << endl;


            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;
                if(valid(ci, cj) && !vis[ci][cj] && maze[ci][cj] == '.') {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                    lvl[ci][cj] = lvl[pi][pj] + 1;

                    // Checker
                    if(ci == 0 || ci == di-1 || cj == 0 || cj == dj-1)
                        return lvl[ci][cj];
                }
            }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int si = entrance[0],
            sj = entrance[1];
        di = maze.size();
        dj = maze[0].size();
        memset(vis, false, sizeof(vis));
        memset(lvl, -1, sizeof(lvl));

        return bfs(maze, si, sj);
    }
};