#include <bits/stdc++.h>
using namespace std;

char grid[100][100];
bool visited[100][100];
vector<pair<int,int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, cols;

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while(!q.empty()) {
        int par_i = q.front().first,
            par_j = q.front().second;
        q.pop();

        cout << par_i << " " << par_j << endl;

        for(int i = 0; i < 4; i++) {
            int ci = par_i + mv[i].first,
                cj = par_j + mv[i].second;
            if(valid(ci, cj) && !visited[ci][cj]) {
                q.push({ci, cj});
                visited[ci][cj] = true;
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
    int si, sj; cin >> si >> sj;
    bfs(si, sj);

    
    return 0;
}
