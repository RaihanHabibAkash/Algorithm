// Problem: Labyrinth
// Platform: CSES
// Link: https://cses.fi/problemset/task/1193
/* 
    Topics: 2D Grid BFS, level tracker, visited tracker,
    parrent tracker, Move Tracking using, moves tracker
*/
/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[1005][1005];
bool vis[1005][1005];
int lvl[1005][1005];
char moves[1005][1005];
pair<int,int> parrent[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    lvl[si][sj] = 0;

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ci = pi + mv[i].first,
                cj = pj + mv[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                q.push({ci,cj});
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pi][pj] + 1;
                parrent[ci][cj] = {pi,pj};
                
                // Moves tracker
                if(i == 0) moves[ci][cj] = 'U';
                else if(i == 1) moves[ci][cj] = 'D';
                else if(i == 2) moves[ci][cj] = 'L';
                else if(i == 3) moves[ci][cj] = 'R';
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
            vis[i][j] = false;
            lvl[i][j] = -1;
            moves[i][j] = '.';
            parrent[i][j] = {-1,-1};

            if(grid[i][j] == 'A') {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'B') {
                di = i;
                dj = j;
            }
        }
    bfs(si, sj);

    if(vis[di][dj]) {
        cout << "YES" << endl;
        cout << lvl[di][dj] << endl;
        
        vector<char> path;
        int ci = di,
            cj = dj;
        while(1) {
            if(grid[ci][cj] == 'A' || ci == -1 || cj == -1)
                break;
            
            path.push_back(moves[ci][cj]);

            pair<int,int> par = parrent[ci][cj];
            int pi = par.first,
                pj = par.second;
            
            ci = pi;
            cj = pj;
        }

        reverse(path.begin(), path.end());
        for(char it : path)
            cout << it;
        cout << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}
