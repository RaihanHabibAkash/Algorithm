#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges; cin >> nodes >> edges;

    int adjacency_matrix[nodes][nodes];
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++) {
            if(i == j) 
                adjacency_matrix[i][j] = 0;
            else 
                adjacency_matrix[i][j] = INT_MAX;
        }

    while(edges--) {
        int a, b, c; cin >> a >> b >> c;
        adjacency_matrix[a][b] = c;
        // dis[b][a] = c; (undirected)
    }

    for(int k = 0; k < nodes; k++)
        for(int i = 0; i < nodes; i++)
            for(int j = 0; j < nodes; j++)
                if(adjacency_matrix[i][k] != INT_MAX && adjacency_matrix[k][j] != INT_MAX && 
                        adjacency_matrix[i][k] + adjacency_matrix[k][j] < adjacency_matrix[i][j])
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
    
    bool cycle = false;
    for(int i = 0 ; i < nodes; i++)
        if(adjacency_matrix[i][i] < 0)
            cycle = true;
    
    if(cycle)
        cout << "Negetive Cycle detected" << endl;
    else {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                if(adjacency_matrix[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}