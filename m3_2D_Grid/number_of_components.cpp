#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];

void dfs(int src) {
    visited[src] = true;

    for(int child : adj_list[src])
        if(!visited[child])
            dfs(child);
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, size(visited));

    int cnt = 0;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            dfs(i); cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
