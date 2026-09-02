#include <bits/stdc++.h>
using namespace std;

int leader[100005];
int grp_size[100005];

int dsu_find(int node) {
    if(leader[node] == -1)
        return node;

    return leader[node] = dsu_find(leader[node]);
}

void dsu_union(int node1, int node2) {
    int l1 = dsu_find(node1),
        l2 = dsu_find(node2);
    if(l1 == l2)
        return;

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
    int nodes, edges; cin >> nodes >> edges;

    for(int i = 1; i <= nodes; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    while(edges--) {
        int a, b; cin >> a >> b;
        dsu_union(a, b);
    }

    vector<int> roads;
    for(int i = 1; i <= nodes; i++)
        if(leader[i] == -1)
            roads.push_back(i);
    cout << roads.size()-1 << endl;
    for(int i = 1; i < (int)roads.size(); i++) {
        cout << roads[0] << " " << roads[i] << endl;
        dsu_union(roads[0], roads[i]);
    }

    return 0;
}