class Solution {
public:
    bool vis[200005];
    vector<int> adj_list[200005];

    void bfs(int src) {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()) {
            int par = q.front();
            q.pop();

            for(int child : adj_list[par]) {
                if(!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        memset(vis, false, sizeof(vis));

        for(vector<int> x : edges) {
            adj_list[x[0]].push_back(x[1]);
            adj_list[x[1]].push_back(x[0]);
        }

        bfs(source);

        return vis[destination];
    }
};