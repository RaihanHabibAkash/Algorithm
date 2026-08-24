/*
You will be given a 2D matrix of size  which will contain only dot() and minus() where dot() means you can go in that cell and minus() means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of two cells - (,) and (,). You need to tell if these  and  cells are in the same component or not. Same component means you can go from  to .

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Next line will contain  and .
Last line will contain  and .
Constraints

Output Format

Output "YES" if those cell are in the same component, "NO" otherwise.
Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0

NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1

YES
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/same-component/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int si, int sj) {
    vis[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + mv[i].first,
            cj = sj + mv[i].second;
        if(valid(ci, cj), !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main() {
    cin >> rows >> cols;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    
    memset(vis, false, sizeof(vis));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    if(grid[si][sj] == '.')
        dfs(si, sj);

    cout << (vis[di][dj] ? "YES" : "NO") << endl;

    return 0;
}