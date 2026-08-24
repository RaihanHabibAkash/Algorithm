#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[105][105];
bool vis[105][105];
pair<int,int> parrent[105][105];
vector<pair<int,int>> mv = {{-1,0},{1,0},{0,1},{0,-1}};

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    vis[si][sj] = true;
    q.push({si, sj});

    while(!q.empty()) {
        int pi = q.front().first,
            pj = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ci = pi + mv[i].first,
                cj = pj + mv[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                parrent[ci][cj] = {pi, pj};
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

            if(grid[i][j] == 'A') {
                si = i;
                sj = j;
            }

            if(grid[i][j] == 'B') {
                di = i;
                dj = j;
            }
        }

        memset(vis, false, sizeof(vis));
        memset(parrent, -1, sizeof(parrent));

        bfs(si, sj);

        int x = di, y = dj;

        while(1) {
            pair<int,int> nd = parrent[x][y];
            x = nd.first;
            y = nd.second;

            if(grid[x][y] == 'A') break;

            grid[x][y] = 'o';
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }

    return 0;
}
