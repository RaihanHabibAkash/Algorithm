#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int parrent[1005];

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
                parrent[child] = par;
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
    memset(parrent, -1, sizeof(parrent));

    int src, des; cin >> src >> des;
    bfs(src);

    // Pusing path in vector
    vector<int> path;
    int node = des;
    while(node != -1) {
        path.push_back(node);
        node = parrent[node]; // update node to his parrent
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
    cout << endl;

    return 0;
}