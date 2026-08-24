/*
You will be given a 2D matrix of size  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain  and .
Next you will be given the 2D matrix.
Constraints

Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/area-of-component/
#include <bits/stdc++.h>
using namespace std;

int rows, cols;
int nds;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int si, int sj) {
    nds++;
    vis[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + mv[i].first,
            cj = sj + mv[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci,cj);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int mn = INT_MAX, flag = false;

    int components = 0;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(!vis[i][j] && grid[i][j] == '.') {
                nds = 0;
                dfs(i, j);
                flag = true;

                if(nds < mn) mn = nds;
            }

    if(flag) cout << mn << endl;
    else cout << -1 << endl;

    return 0;
}