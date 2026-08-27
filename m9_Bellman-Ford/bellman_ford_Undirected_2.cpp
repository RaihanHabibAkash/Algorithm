#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int dis[1005];
    vector<tuple<int,int,int>> edge_list;

    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        edge_list.push_back({a,b,c});
        edge_list.push_back({b,a,c}); // undirected
    }

    for(int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;
    dis[0] = 0; // src always 0

    // Edge relaxation n-1 times
    for(int i = 1; i <= nodes-1; i++)
        for(auto [a, b, c] : edge_list)
            if(dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
    // Extra 1 time for cycle detection
    bool cycle = false;
    for(auto [a, b, c] : edge_list)
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]) {
                cycle = true;
                break;
            }

    if(cycle) cout << "Negative Cycle" << endl;
    else 
        for(int i = 0; i < nodes; i++)
            cout << i << " -> " << dis[i] << endl;

    return 0;
}
// In negetive cycilic graph dont have ans. it relax edges every time