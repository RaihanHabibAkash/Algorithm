#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

int bfs(int srcNd, int desNd) {
    queue<pair<int,int>> q;
    q.push({srcNd,0});
    visited[srcNd] = true;


    while(!q.empty()) {
        int par = q.front().first;
        int level = q.front().second;
        q.pop();

        if(par == desNd) return level;

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push({child, level+1});
                visited[child] = true;
            }
        }
    }

    return -1;
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
    cout << bfs(src, des) << endl;

    return 0;
}
