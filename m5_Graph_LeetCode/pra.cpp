class Solution {
public:
    int rows, cols;
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    bool vis[305][305];

    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<char>>& grid, int si, int sj) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        vis[si][sj] = true;

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;

                if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1') {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int cnt = 0;
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == '1' && !vis[i][j]) {
                    bfs(grid, i, j);
                    cnt++;
                }
        return cnt;
    }
};