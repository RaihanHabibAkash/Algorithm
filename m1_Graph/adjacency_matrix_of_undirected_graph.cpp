#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int adj_mat[nodes][nodes];
    // 2D array ar sob value memory te 0 kortechi
    memset(adj_mat, 0, sizeof(adj_mat));

    // Sob connection gulo dibo undirected ar 
    for(int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // undirected
    }

    // Prime diagonal ar value 1 dibo
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