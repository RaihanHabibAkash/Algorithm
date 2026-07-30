#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int parrent[105]; // parrent tracker
bool cycle = false;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(vis[child] && child != parrent[par])
                cycle = true;

            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                parrent[child] = par;
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parrent, -1, sizeof(parrent));
    
    for(int i = 0; i < nodes; i++)
        if(!vis[i]) bfs(i);

    cout << (cycle ? "Cycle detected" : "No Cycle") << endl; 

    return 0;
}