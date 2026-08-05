// Problem: Counting Rooms
// Platform: CSES
// Difficulty: Medium
// Link: https://cses.fi/problemset/task/1192
// Topics: 2D Grid DFS, Components count
/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int row, int col) {
    vis[row][col] = true;

    for(int i = 0; i < 4; i++) {
        int child_row = row + mv[i].first,
            child_col = col + mv[i].second;
        
        if(valid(child_row, child_col) && grid[child_row][child_col] == '.' && !vis[child_row][child_col])
            dfs(child_row, child_col);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            vis[i][j] = false;
        }
    
    int rooms = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(grid[i][j] == '.' && !vis[i][j]) {
                rooms++;
                dfs(i, j);
            }

    cout << rooms << endl;

    return 0;
}