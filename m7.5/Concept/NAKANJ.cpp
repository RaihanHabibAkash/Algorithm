// Problem: NAKANJ - Minimum Knight Moves
// Platform: SPOJ
// Difficulty: Easy
// Link: https://www.spoj.com/problems/NAKANJ/
// Topics: 2D Grid, BFS, level tracker
/*
NAKANJ - Minimum Knight moves !!!
#bfs

Anjali and Nakul are good friends. They both had a quarrel recently while playing chess. Nakul wants to know the minimum number of moves a knight takes to reach from one square to another square of a chess board (8 × 8). Nakul is brilliant and he had already written a program to solve the problem. Nakul wants to know whether Anjali can do it. Anjali is very weak in programming. Help her to solve the problem.

A knight can move in the shape of an "L" in a chessboard - two squares either forward, backward, left, or right and then one square to its left or right. A knight move is valid if it moves as mentioned above and it is within the boundary of the chessboard (8 × 8).

knight

Input
There are T test cases in total. The next T lines contain two strings (start and destination) separated by a space.

The strings start and destination will only contain two characters - First character is an alphabet between 'a' and 'h' (inclusive), Second character is a digit between '1' and '8' (inclusive) - (Quotes just for clarity).

To know the knight moves more clearly refer to the above figure.

Output
Print the minimum number of moves a knight takes to reach from start to destination in a separate line.

Constraints
1 ≤ T ≤ 4096

Example
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/
#include <bits/stdc++.h>
using namespace std;

int rows = 8, cols = 8;
bool vis[8][8];
int lvl[8][8];
vector<pair<int,int>> knight_mv = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{2,1},{1,2},{-1,2}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    lvl[si][sj] = 0;

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int ci = pi + knight_mv[i].first,
                cj = pj + knight_mv[i].second;
            
            if(valid(ci, cj) && !vis[ci][cj]) {
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pi][pj] + 1;
                q.push({ci, cj});
            }
        }
    }
}

int main() {
    int cs; cin >> cs;

    while(cs--) {
        string src, dst; cin >> src >> dst;
        int si = src[1] - '1',
            sj = src[0] - 'a',
            di = dst[1] - '1',
            dj = dst[0] - 'a';
        
        memset(vis, false, sizeof(vis));
        memset(lvl, -1, sizeof(lvl));

        bfs(si, sj);
        cout << lvl[di][dj] << endl;
    }

    return 0;
}