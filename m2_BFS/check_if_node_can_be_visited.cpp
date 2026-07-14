#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int srcNd) {
    queue<int> q;
    q.push(srcNd);
    visited[srcNd] = true;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
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
    memset(visited, false, sizeof(visited));

    int src, des; cin >> src >> des;
    bfs(src);

    if(visited[des]) cout << "Ache" << endl;
    else cout << "Nai" << endl;

    return 0;
}