#include <bits/stdc++.h>
using namespace std;

char grid[100][100];
bool visited[100][100]; // node visited checker
vector<pair<int,int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // moves 4 ways
int rows, cols;

bool valid(int i, int j) { // valid index checker
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int si, int sj) { // 2D grid node index
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + mv[i].first,
            cj = sj + mv[i].second;
        if(valid(ci, cj) && !visited[ci][cj]) // If the move is valid call dfs
            dfs(ci, cj);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));

    int si, sj; cin >> si >> sj; // src node
    dfs(si, sj);

    return 0;
}