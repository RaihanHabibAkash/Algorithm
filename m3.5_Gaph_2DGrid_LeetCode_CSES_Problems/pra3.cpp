#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool visited[100];
vector<int> v;
int cnt = 0;

void dfs(int src) {
    visited[src] = true;
    cnt++;

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
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < nodes; i++) {
        if(!visited[i]) {
            cnt = 0;
            dfs(i);
            v.push_back(cnt);
        }
    }

    sort(v.begin(), v.end());
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
