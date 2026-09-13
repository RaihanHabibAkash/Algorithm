// MST --> Minimum spanning Tree (Kruskal's Algo to get MST from graph)
#include <bits/stdc++.h>
using namespace std;

int leader[1005];
int grp_size[1005];

bool cmp(tuple<int,int,int> l, tuple<int,int,int> r) {
    return get<2>(l) < get<2>(r);
}

int dsu_find(int node) {
    if(leader[node] == -1) return node;

    return leader[node] = dsu_find(leader[node]);
}

void dsu_union(int node1, int node2) {
    int l1 = dsu_find(node1),
        l2 = dsu_find(node2);
    
    if(grp_size[l1] >= grp_size[l2]) {
        leader[l2] = l1;
        grp_size[l1] += grp_size[l2];
    }
    else {
        leader[l1] = l2;
        grp_size[l2] += grp_size[l1];
    }
}

int main() {
    // Setting default values
    for(int i = 0; i < 1005; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    int nodes, edges; cin >> nodes >> edges;
    vector<tuple<int,int,int>> edge_list;

    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        edge_list.push_back({a,b,c});
    }
    sort(edge_list.begin(), edge_list.end(), cmp);

    int totalCost = 0;
    for(auto [a,b,c] : edge_list) {
        int l1 = dsu_find(a),
            l2 = dsu_find(b);
        
        if(l1 != l2) {
            dsu_union(l1, l2);
            totalCost += c;
        }
    }

    cout << totalCost << endl;

    return 0;
}