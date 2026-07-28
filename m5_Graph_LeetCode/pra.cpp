class Solution {
public:
    bool vis[505][505];
    vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
    int rows, cols;
    bool flag;
    
    bool valid(int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        return true;
    }

    void bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int si, int sj) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        vis[si][sj] = true;

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();

            if(grid1[pi][pj] != 1) flag = false;

            for(int i = 0; i < 4; i++) {
                int ci = pi + mv[i].first,
                    cj = pj + mv[i].second;
                if(valid(ci, cj) && grid2[ci][cj] == 1 && !vis[ci][cj]) {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid2.size();
        cols = grid2[0].size();
        memset(vis, false, sizeof(vis));
        int cnt = 0;

        for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++)
                if(grid2[i][j] == 1 && !vis[i][j]) {
                    flag = true;
                    bfs(grid1, grid2, i, j);
                    if(flag) cnt++;
                }
        return cnt;
    }
};