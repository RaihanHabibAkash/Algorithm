#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[10005];
int dis[10005];

class cmp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    dis[src] = 0;
    pq.push({src, 0});

    while(!pq.empty()) {
        int par_node = pq.top().first,
            par_dis = pq.top().second;
        pq.pop();

        // parrent distance boro hoile onno node baki distance boro e hobe
        if(par_dis > dis[par_node]) continue;

        for(pair<int,int> child : adj_list[par_node]) {
            int child_node = child.first,
                child_dis = child.second;
            
            if(par_dis + child_dis < dis[child_node]) {
                dis[child_node] = par_dis + child_dis;
                pq.push({child_node, dis[child_node]});
            }
        }
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for(int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for(int i = 0; i < nodes; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}
