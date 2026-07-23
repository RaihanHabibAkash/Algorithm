/*
You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
Constraints

Output Format

Output the number of apartments
Sample Input 0

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 0

3
Sample Input 1

6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#
Sample Output 1

5
*/
// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/count-apartments/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int src_row, int src_col) {
    queue<pair<int,int>> q;
    q.push({src_row, src_col});
    visited[src_row][src_col] = true;

    while(!q.empty()) {
        int par_row = q.front().first,
            par_col = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int child_row = par_row + mv[i].first,
                child_col = par_col + mv[i].second;
            
            if(valid(child_row, child_col) && grid[child_row][child_col] == '.' && !visited[child_row][child_col]) {
                q.push({child_row, child_col});
                visited[child_row][child_col] = true;
            }
        }
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    memset(visited, false, sizeof(visited));

    int components = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j); components++;
            }
        }
    }

    cout << components << endl;

    return 0;
}