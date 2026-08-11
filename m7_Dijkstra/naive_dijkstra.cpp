#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[1005];
int dis[1005];

void dijkstra(int src) {
    queue<pair<int,int>> q;
    dis[src] = 0;
    q.push({src, 0});

    while(!q.empty()) {
        int par_node = q.front().first,
            par_dis = q.front().second;
        q.pop();

        for(pair<int,int> child : adj_list[par_node]) {
            int child_node = child.first,
                child_dis = child.second;

            // Path relaxation
            if(par_dis + child_dis < dis[child_node]) {
                dis[child_node] = par_dis + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    
    // Taking input
    while(edges--) {
        int a,b,c; cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});    
    }

    // Making all nodes distance INT_MAX
    for(int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    // Printing
    for(int i = 0; i < nodes; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}
