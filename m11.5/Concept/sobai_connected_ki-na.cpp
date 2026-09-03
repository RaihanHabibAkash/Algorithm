#include <bits/stdc++.h>
using namespace std;

int leader[1005];
int grp_size[1005];

int dsu_find(int node) {
    if(leader[node] == -1)
        return node;
    
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
    int nodes, edges; cin >> nodes >> edges;

    // Setting the default values of arrays
    for(int i = 1; i <= nodes; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    while(edges--) {
        int a, b; cin >> a >> b;
        int l1 = dsu_find(a),
            l2 = dsu_find(b);

        if(l1 != l2)
            dsu_union(a, b);
    }

    int cnt = 0;
    for(int i = 1; i <= nodes; i++) {
        if(leader[i] == -1)
            cnt++;
        if(cnt > 1)
            break;
    }

    if(cnt > 1)
        cout << "Sobai Connected nai" << endl;
    else
        cout << "Sobai Connect" << endl; // leader 1 ta

    return 0;
}
