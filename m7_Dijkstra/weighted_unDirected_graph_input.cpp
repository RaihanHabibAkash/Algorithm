#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    vector<pair<int,int>> adj_list[nodes];

    // Taking input
    while(edges--) {
        int a,b,c; cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});    
    }

    // Printing
    for(int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for(pair<int,int> p : adj_list[i])
            cout << p.first << " " << p.second << ", ";
        cout << endl;
    }

    return 0;
}
