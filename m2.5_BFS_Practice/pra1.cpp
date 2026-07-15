#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];

void bst(int srcNd, int dst, bool *visited, int *level) {
    queue<int> q;
    q.push(srcNd);
    visited[srcNd] = true;
    level[srcNd] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                level[child] = level[par]+1;
                visited[child] = true;
            }
        }
    }

    // Printing
    if(!visited[dst]) cout << -1 << endl;
    else cout << level[dst] << endl;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int queries; cin >> queries;
    while(queries--) {
        bool visited[100]; int level[100];
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        int src, dst; cin >> src >> dst;
        bst(src, dst, visited, level);
    }

    return 0;
}
