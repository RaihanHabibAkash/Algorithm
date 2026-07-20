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

void dfs(int si, int sj) {
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + mv[i].first,
            cj = sj + mv[i].second;
        
        if(valid(ci, cj) && !visited[ci][cj])
            dfs(ci, cj);
    }
}


int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    memset(visited, false, sizeof(visited));

    int si, sj; cin >> si >> sj;
    dfs(si, sj);
    
    return 0;
}
