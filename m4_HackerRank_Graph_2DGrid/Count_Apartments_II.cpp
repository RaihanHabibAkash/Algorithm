/*
You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number rooms in each of the apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

You need to print the count of the rooms in ascending order. If there are no apartments available in that building, then you should print .

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
Constraints

Output Format

Output the number of rooms in each of the apartments in ascending order.
Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 0

2 2 8
Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#
Sample Output 1

1 1 2 8 10
*/
// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/count-apartments-ii/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
int cnt;

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int src_row, int src_col) {
    visited[src_row][src_col] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int child_row = src_row + mv[i].first,
            child_col = src_col + mv[i].second;

        if(valid(child_row, child_col) && grid[child_row][child_col] == '.' && !visited[child_row][child_col])
            dfs(child_row, child_col);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    memset(visited, false, sizeof(visited));

    vector<int> rooms;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                rooms.push_back(cnt);
            }
        }
    }

    if(rooms.empty()) cout << 0 << endl;
    else {
        sort(rooms.begin(), rooms.end());
        for(int room : rooms) cout << room << " ";
        cout << endl;
    }

    return 0;
}