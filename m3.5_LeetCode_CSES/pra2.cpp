#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool visited[100];

void dfs(int srcNd) {
    visited[srcNd] = true;

    for(int child : adj_list[srcNd])
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

    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            dfs(i); cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
