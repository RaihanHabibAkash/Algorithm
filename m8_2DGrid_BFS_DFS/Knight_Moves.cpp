/*
You will be given a chessboard of  size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell  ( and ), and the queen's cell  ( and ). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below: image

Input Format

First line will contain , the number of test cases.
First line of each test case will contain  and .
Second line of each test case will contain  and .
Third line of each test case will contain  and .
Constraints

Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print .
Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1
Explanation 0

For the first test case, one of the possible answer could be this way:
image
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool vis[105][105];
int lvl[105][105];
vector<pair<int,int>> knight_mv = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{2,1},{1,2},{-1,2}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    vis[si][sj] = true;
    lvl[si][sj] = 0;
    q.push({si,sj});

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int ci = pi + knight_mv[i].first,
                cj = pj + knight_mv[i].second;
            if(valid(ci,cj) && !vis[ci][cj]) {
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pi][pj] + 1;
                q.push({ci,cj});
            }
        }
    }
}

int main() {
    int cs; cin >> cs;
    while(cs--) {
        cin >> rows >> cols;

        memset(vis, false, sizeof(vis));
        memset(lvl, -1, sizeof(lvl));

        int si, sj, di, dj; 
        cin >> si >> sj >> di >> dj;

        bfs(si, sj);
        cout << lvl[di][dj] << endl;
    }

    return 0;
}