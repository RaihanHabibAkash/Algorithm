#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;
    int adj_mat[nodes][nodes]; // adjacency matrix

    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++) {
            if(i == j)
                adj_mat[i][j] = 0;
            else 
                adj_mat[i][j] = INT_MAX;
        }
    
    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; Undirected graph
    }
    // checking (i --> k --> j) < (i --> j)
    for(int k = 0; k < nodes; k++)
        for(int i = 0; i < nodes; i++)
            for(int j = 0; j < nodes; j++)
                if(adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
    
    // If prime diagonal has - (val < 0) value means negetive weighted cycle (no ans)
    bool cycle = false;
    for(int i = 0; i < nodes; i++)
        if(adj_mat[i][i] < 0)
            cycle = true;
    
    if(cycle)
        cout << "Negetive Cycle detected" << endl;
    else {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                if(adj_mat[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << adj_mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}