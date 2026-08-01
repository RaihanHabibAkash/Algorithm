#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool visited[100];
int cnt = 0;

void dfs(int srcNd) {
    cnt++;
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

    int src; cin >> src;
    dfs(src);

    cout << cnt << endl;

    return 0;
}
