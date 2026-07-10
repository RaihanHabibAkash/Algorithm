#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int adj_mat[nodes][nodes];
    // Matrix ar sob value 0 in memory
    memset(adj_mat, 0, sizeof(adj_mat));

    // Connection gulo 1 korbe directed graph ar jnn
    for(int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    // Prime diagonal ar value sob 1 hobe
    for(int i = 0; i < nodes; i++)
        adj_mat[i][i] = 1;

    // Printing
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++)
            cout << adj_mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
