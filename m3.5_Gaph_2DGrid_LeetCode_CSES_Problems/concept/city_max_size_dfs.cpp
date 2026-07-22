#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[100][100];
bool visited[100][100];
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int cnt;

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int src_row, int src_col) {
    visited[src_row][src_col] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int child_row = src_row + mv[i].first,
            child_col = src_col + mv[i].second;

        if(valid(child_row, child_col) && !visited[child_row][child_col] && grid[child_row][child_col] == '.')
            dfs(child_row, child_col);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    memset(visited, false, sizeof(visited));
    
    int mx_size = -1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                if(mx_size < cnt) mx_size = cnt;
            }
        }
    }

    cout << mx_size << endl;
    
    return 0;
}
