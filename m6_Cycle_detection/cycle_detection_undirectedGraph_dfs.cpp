#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool vis[100];
int parrent[100];
bool cycle = false;

void dfs(int src) {
    vis[src] = true;

    for(int child : adj_list[src]) {
        if(vis[child] && child != parrent[src])
            cycle = true;

        if(!vis[child]) {
            parrent[child] = src;
            dfs(child);
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

    for(int i = 0; i < nodes; i++)
        if(!vis[i]) dfs(i);

    // Hudai, to see correct parrent or not
    // for(int i = 0; i < nodes; i++)
    //     cout << i << " parrent-> " << parrent[i] << endl;
    
    cout << (cycle ? "Cycle ditected" : "No Cycle") << endl;

    return 0;
}
