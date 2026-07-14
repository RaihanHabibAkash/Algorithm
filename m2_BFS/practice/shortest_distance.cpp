#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[15];
bool visited[15];
int level[15];

void bfs(int srcNd) {
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
                level[child] = level[par] + 1;
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
    memset(level, -1, sizeof(level));
    
    int src, dst; cin >> src >> dst;
    bfs(src);

    cout << level[dst] << endl;

    return 0;
}
