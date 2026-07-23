/*
You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall, a floor or a room. You will be given two rooms  and . You need to tell if you can go from room  to  by passing through the floors. You can walk left, right, up, and down through the floor cells. You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is .(floor), #(wall), A or B (rooms).
Constraints

Output Format

Output YES if you can go from room  to , NO otherwise.
Sample Input 0

5 8
########
#.A#...#
#.##.#B#
#......#
########
Sample Output 0

YES
*/
// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/can-go-1/
#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
int rows, cols;

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '#')
        return false;
    return true;
}

void dfs(int src_row, int src_col) {
    visited[src_row][src_col] = true;

    for(int i = 0; i < 4; i++) {
        int child_row = src_row + mv[i].first,
            child_col = src_col + mv[i].second;
        if(valid(child_row, child_col) && !visited[child_row][child_col])
            dfs(child_row, child_col);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));

    int b_row, b_col;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 'A')
                dfs(i, j);
            if(grid[i][j] == 'B') {
                b_row = i;
                b_col = j;
            }
        }
    }

    cout << ((visited[b_row][b_col]) ? "YES" : "NO") << endl;

    return 0;
}