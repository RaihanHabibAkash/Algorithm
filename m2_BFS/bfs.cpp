#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005]; // Array of vectors
bool visited[1005];

void bfs(int srcNd) {
    queue<int> q;
    q.push(srcNd);
    visited[srcNd] = true;

    while(!q.empty()) {
        // 1. Queue theke node ber kore ana
        int par = q.front();
        q.pop();

        // 2. Oi node nia kaj
        cout << par << " ";

        // 3. Node ar child push in the queue
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
        adj_list[b].push_back(a); // undirected graph
    }
    memset(visited, false, sizeof(visited)); // array all value is set to false

    bfs(0); // source node

    return 0;
}