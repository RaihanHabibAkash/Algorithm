#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    vector<int> adjacency_list[nodes];

    while(edges--) {
        int a, b; cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    int queries; cin >> queries;
    while(queries--) {
        vector<int> v;
        int node; cin >> node;
        for(int child : adjacency_list[node])
            v.push_back(child);

        // Empty vector
        if(v.empty()) {
            cout << -1 << endl;
            continue;
        }

        sort(v.begin(), v.end(), greater<int>());
        for(int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}