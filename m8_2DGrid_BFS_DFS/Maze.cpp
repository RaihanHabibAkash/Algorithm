/*
Rezia is trapped in a 2D maze of  size, starting at position R, and her goal is to reach the exit marked by D. The maze contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early as possible, we need to determine the path she will follow.

Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the maze unchanged.

Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: attempting right first, then left, followed by up, and finally down.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the final maze with marked X indicating the path she will follow.
Sample Input 0

5 6
...D.#
.##..#
....#.
.R#...
.#.##.
Sample Output 0

...D.#
.##X.#
.XXX#.
.R#...
.#.##.
Sample Input 1

5 6
...D.#
.R...#
....#.
..#...
.#.##.
Sample Output 1

...D.#
.RXX.#
....#.
..#...
.#.##.
Sample Input 2

5 6
...D.#
.....#
.##.#.
.R#...
.#.##.
Sample Output 2

...D.#
XXXX.#
X##.#.
XR#...
.#.##.
Sample Input 3

5 6
...D.#
.....#
###.#.
.R#...
.#.##.
Sample Output 3

...D.#
.....#
###.#.
.R#...
.#.##.
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/maze-19/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[1005][1005];
int vis[1005][1005];
pair<int,int> parrent[1005][1005];
vector<pair<int,int>> mv = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ci = pi + mv[i].first,
                cj = pj + mv[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                parrent[ci][cj] = {pi,pj};
                vis[ci][cj] = true;
                q.push({ci,cj});
            }
        }
    }
}

int main() {
    cin >> rows >> cols;
    int si, sj, di, dj;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            
            if(grid[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    
    memset(vis, false, sizeof(vis));
    memset(parrent, -1, sizeof(parrent));
    bfs(si, sj);

    if(vis[di][dj]) {
        int x = di, y = dj;

        while(1) {
            pair<int,int> par = parrent[x][y];
            x = par.first;
            y = par.second;
            
            if(grid[x][y] == 'R') break;

            grid[x][y] = 'X';
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}