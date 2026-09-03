// Problem: Building Roads
// Platform: CSES
// Difficulty: Easy
// Link: https://cses.fi/problemset/task/1666/
// Topics: Udirected Graph DFS

/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3
*/

#include <bits/stdc++.h>
using namespace std;

int leader[100005];

int dsu_find(int node) {
    if(leader[node] == -1)
        return node;

    return leader[node] = dsu_find(leader[node]);
}

void dsu_union(int node1, int node2) {
    int l1 = dsu_find(node1),
        l2 = dsu_find(node2);

    if(l1 < l2)
        leader[l2] = l1;
    else
        leader[l1] = l2;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    memset(leader, -1, sizeof(leader));

    while(edges--) {
        int a, b; cin >> a >> b;

        int l1 = dsu_find(a),
            l2 = dsu_find(b);

        if(l1 != l2)
            dsu_union(a, b);
    }

    vector<int> ans;
    for(int i = 2; i <= nodes; i++) {
        int ldr = dsu_find(i);

        if(ldr != 1) {
            ans.push_back(ldr);
            dsu_union(1, ldr);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++)
        cout << 1 << " " << ans[i] << endl;

    return 0;
}