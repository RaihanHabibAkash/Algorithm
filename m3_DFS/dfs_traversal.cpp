#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool visited[100];

void dfs(int srcNd) {
    cout << srcNd << " ";
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

    dfs(0);

    return 0;
}
