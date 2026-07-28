class Solution {
public:
    int rows, cols, cnt;
    bool vis[55][55];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while(!q.empty()) {
            int si = q.front().first,
                sj = q.front().second;

            q.pop();

            cnt++;

            for(int ind = 0; ind < 4; ind++) {
                int ci = si + mv[ind].first,
                    cj = sj + mv[ind].second;
                if(valid(ci, cj) && grid[ci][cj] == 1 && !vis[ci][cj]) {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        } 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(vis, false, sizeof(vis));
        int mx = 0;

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 1 && !vis[i][j]) {
                    cnt = 0;
                    bfs(grid, i, j);
                    if(mx < cnt) mx = cnt;
                }
        return mx;
    }
};