#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges, queries; cin >> nodes >> edges >> queries;
    int dis[505];
    vector<tuple<int,int,int>> edge_list;
    
    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        edge_list.push_back({a,b,c});
        edge_list.push_back({b,a,c});
    }

    while(queries--) {
        for(int i = 0; i <= nodes; i++)
            dis[i] = INT_MAX;

        int src, dst; cin >> src >> dst;
        dis[src] = 0;

        for(int i = 1; i <= nodes-1; i++)
            for(auto [a,b,c] : edge_list)
                if(dis[a] != INT_MAX && dis[a] + c < dis[b])
                    dis[b] = dis[a] + c;

        if(dis[dst] == INT_MAX) cout << -1 << endl;
        else cout << dis[dst] << endl;
    }    

    return 0;
}