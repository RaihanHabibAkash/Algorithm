// Problem: Road Construction
// Platform: CSES
// Link: https://cses.fi/problemset/task/1676/
// Topics: DSU
/*
Time limit: 1.00 s
Memory limit: 512 MB

There are n cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is constructed between cities a and b.
You may assume that every road will be constructed between two different cities.
Output
Print m lines: the required information after each day.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
4 5

Output:
4 2
3 3
2 3
*/
#include <bits/stdc++.h>
using namespace std;

int leader[100005];
int grp_size[100005];
int mx_grp_size = 0;

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
        mx_grp_size = max(mx_grp_size, grp_size[l1]);
    }
    else {
        leader[l1] = l2;
        grp_size[l2] += grp_size[l1];
        mx_grp_size = max(mx_grp_size, grp_size[l2]);
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int componenets = nodes;

    // Set the array default values
    for(int i = 1; i <= nodes; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    while(edges--) {
        int a, b; cin >> a >> b;
        
        int l1 = dsu_find(a),
            l2 = dsu_find(b);
        if(l1 != l2) {
            componenets--;
            dsu_union(a, b);
        }

        cout << componenets << " " << mx_grp_size << endl;
    }

    return 0;
}