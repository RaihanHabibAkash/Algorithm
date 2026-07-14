#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[15];
bool visited[15];
int parrent[15];

void bst(int srcNd) {
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

    int src, dst; cin >> src >> dst;
    bst(src);

    int node = dst;
    vector<int> path;
    while(node != -1) {
        path.push_back(node);
        node = parrent[node];
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
    cout << endl;

    return 0;
}
