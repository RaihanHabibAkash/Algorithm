#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100]; // array of vectors

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int node; cin >> node;
    cout << adj_list[node].size() << endl;

    return 0;
}
