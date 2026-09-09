// Problem: Roads not only in Berland
// Platform: Codeforces
// Rating: 1900
// Link: https://codeforces.com/contest/25/problem/D
// Solved: DSU, Vector & queue of pair logic
/*
Berland Government decided to improve relations with neighboring countries. First of all, it was decided to build new roads so that from each city of Berland and neighboring countries it became possible to reach all the others. There are n cities in Berland and neighboring countries in total and exactly n - 1 two-way roads. Because of the recent financial crisis, the Berland Government is strongly pressed for money, so to build a new road it has to close some of the existing ones. Every day it is possible to close one existing road and immediately build a new one. Your task is to determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others, and to draw a plan of closure of old roads and building of new ones.

Input
The first line contains integer n (2 ≤ n ≤ 1000) — amount of cities in Berland and neighboring countries. Next n - 1 lines contain the description of roads. Each road is described by two space-separated integers ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — pair of cities, which the road connects. It can't be more than one road between a pair of cities. No road connects the city with itself.

Output
Output the answer, number t — what is the least amount of days needed to rebuild roads so that from each city it became possible to reach all the others. Then output t lines — the plan of closure of old roads and building of new ones. Each line should describe one day in the format i j u v — it means that road between cities i and j became closed and a new road between cities u and v is built. Cities are numbered from 1. If the answer is not unique, output any.

Examples
InputCopy
2
1 2
OutputCopy
0
InputCopy
7
1 2
2 3
3 1
4 5
5 6
6 7
OutputCopy
1
3 1 3 7
*/
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
    int nodes; cin >> nodes;
    int edges = nodes - 1;

    for(int i = 1; i <= nodes; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    queue<pair<int,int>> dlt;

    while(edges--) {
        int a, b; cin >> a >> b;

        int l1 = dsu_find(a),
            l2 = dsu_find(b);

        if(l1 != l2)
            dsu_union(l1, l2);
        else
            dlt.push({a,b});
    }

    vector<int> nds;
    for(int i = 1; i <= nodes; i++)
        if(leader[i] == -1)
            nds.push_back(i);

    cout << nds.size() - 1 << endl;
    int i = 1;
    while(!dlt.empty() && i < nds.size()) {
        cout << dlt.front().first << " " << dlt.front().second << " ";
        dlt.pop();

        dsu_union(nds[0], nds[i]);
        cout << nds[0] << " " << nds[i++] << endl;
    }

    return 0;
}