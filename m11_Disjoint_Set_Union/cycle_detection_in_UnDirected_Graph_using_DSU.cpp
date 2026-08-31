#include <bits/stdc++.h>
using namespace std;

int leader[1005];
int grp_size[1005];

int dsu_find(int node) {
    if(leader[node] == -1)
        return node;

    int l = dsu_find(leader[node]);
    leader[node] = l;

    return l;
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
    memset(leader, -1, sizeof(leader));
    fill(grp_size, grp_size + 1005, 1);
    int nodes, edges; cin >> nodes >> edges;

    bool cycle = false;
    while(edges--) {
        int a, b; cin >> a >> b;
        int l1 = dsu_find(a),
            l2 = dsu_find(b);

        if(l1 == l2)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if(cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}