#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int graph[nodes][nodes] = {0};

    for(int i = 0; i < edges; i++) {
        int l, r; cin >> l >> r;
        graph[l][r] = 1;
        graph[r][l] = 1;
    }

    for(int i = 0; i < nodes; i++)
        graph[i][i] = 1;

    return 0;
}
