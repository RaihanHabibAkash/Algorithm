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
    fill(grp_size, grp_size + 100, 1);

    dsu_union(1, 2);
    dsu_union(0, 2);
    dsu_union(3, 4);
    dsu_union(0, 4);

    cout << "Leader: ";
    for(int i = 0; i < 5; i++)
        cout << i << "->" << leader[i] << " | ";
    cout << endl << endl;

    cout << "Group Size: ";
    for(int i = 0; i < 5; i++)
        cout << i << "->" << grp_size[i] << " | ";
    cout << endl;
    
    return 0;
}
