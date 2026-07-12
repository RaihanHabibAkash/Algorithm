#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    vector<pair<int,int>> edge_list;

    while(edges--) {
        int a, b; cin >> a >> b;
        edge_list.push_back({a,b});
    }

    for(pair<int,int> p : edge_list)
        cout << p.first << " - " << p.second << endl;

    return 0;
}