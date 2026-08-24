#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
int parrent[105];
bool vis[105];

void bfs(int src) {
    queue<int> q;
    vis[src] = true;
    q.push(src);

    // path manupulation
    q.push(4);

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par])
            if(!vis[child]) {
                vis[child] = true;
                parrent[child] = par;
                q.push(child);
            }
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parrent, -1, sizeof(parrent));

    int src = 0, dst = 2;
    bfs(src);

    vector<int> path;
    int node = dst;
    while(node != -1) {
        path.push_back(node);
        node = parrent[node];
    }

    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;

    return 0;
}