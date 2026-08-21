class Solution {
public:
    vector<int> ans;
    bool vis[10005];
    bool pathVis[10005];

    bool dfs(vector<vector<int>>& graph, int src) {
        vis[src] = true;
        pathVis[src] = true;

        for(int child : graph[src]) {
            if(vis[child] && pathVis[child])
                return false;

            if(!vis[child])
                if(!dfs(graph, child))
                    return false;
        }

        ans.push_back(src);
        pathVis[src] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(vis, false, sizeof(vis));
        memset(pathVis, false, sizeof(pathVis));

        for(int i = 0; i < graph.size(); i++)
            if(!vis[i])
                dfs(graph, i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};