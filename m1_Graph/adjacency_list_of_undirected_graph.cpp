#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    vector<int> adj_list[nodes]; // array of vectors

    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // Printing
    for(int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for(int x : adj_list[i]) cout << x << " ";
        cout << endl;
    }

    return 0;
}
