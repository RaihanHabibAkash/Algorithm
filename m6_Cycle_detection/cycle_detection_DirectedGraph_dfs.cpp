#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool vis[100];
bool pathVis[100];
bool cycle = false;

void dfs(int src) {
    vis[src] = true;
    pathVis[src] = true;

    for(int child : adj_list[src]) {
        if(vis[child] && pathVis[child]) cycle = true;

        if(!vis[child]) dfs(child);
    }
    pathVis[src] = false;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));

    for(int i = 0; i < nodes; i++)
        if(!vis[i]) dfs(i);

    cout << (cycle ? "Cycle detected" : "No Cycle") << endl;

    return 0;
}
