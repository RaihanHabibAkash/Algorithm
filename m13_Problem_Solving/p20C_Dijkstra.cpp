// Problem: Dijkstra?
// Platform: Codeforces
// Rating: 1900
// Link: https://codeforces.com/contest/20/problem/C
// Solved: Dijkstra
/*
C. Dijkstra?
time limit per test1 second
memory limit per test64 megabytes
You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

Examples
InputCopy
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
OutputCopy
1 4 3 5 
InputCopy
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
OutputCopy
1 4 3 5
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class cmp {
public:
    bool operator()(pair<ll,ll> l, pair<ll,ll> r) {
        return l.second > r.second;
    }
};

int parrent[100000 + 100];
ll dis[100000 + 100];
vector<pair<ll,ll>> adj_list[100000 + 100];

void dijkstra(int src) {
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while(!pq.empty()) {
        ll par_nd = pq.top().first,
            par_dis = pq.top().second;
        pq.pop();

        if(par_dis > dis[par_nd])
            continue;

        for(pair<ll,ll> child : adj_list[par_nd]) {
            ll child_nd = child.first,
                child_dis = child.second;

            if(par_dis + child_dis < dis[child_nd]) {
                dis[child_nd] = par_dis + child_dis;
                pq.push({child_nd, dis[child_nd]});
                parrent[child_nd] = par_nd;
            }
        }
    }
}

int main() {
    ll nodes, edges; cin >> nodes >> edges;

    // Setting the default values
    for(int i = 1; i <= nodes; i++) {
        dis[i] = LLONG_MAX;
        parrent[i] = -1;
    }

    while(edges--) {
        ll a, b, c; cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    dijkstra(1);
    if(dis[nodes] == LLONG_MAX)
        cout << -1 << endl;
    else {
        vector<ll> ans;
        ll node = nodes;
        while(node != -1) {
            ans.push_back(node);
            node = parrent[node];
        }

        reverse(ans.begin(), ans.end());
        for(ll x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}