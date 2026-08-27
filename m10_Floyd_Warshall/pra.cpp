#include <bits/stdc++.h>
using namespace std;

int dis[505];
vector<pair<int,int>> adj_list[505];

class cmp {
public:
    bool operator()(pair<int,int> l, pair<int,int> r) {
        return l.second > r.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while(!pq.empty()) {
        int par_node = pq.top().first,
            par_dis = pq.top().second;
        pq.pop();

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
    int nodes, edges, queris; cin >> nodes >> edges >> queris;

    while(edges--) {
        int a, b, c; cin >> a>> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    while(queris--) {
        int a, b; cin >> a >> b;
        for(int i = 0; i <= nodes; i++)
            dis[i] = INT_MAX;

        dijkstra(a);

        if(dis[b] == INT_MAX) cout << -1 << endl;
        else cout << dis[b] << endl;
    }

    return 0;
}
