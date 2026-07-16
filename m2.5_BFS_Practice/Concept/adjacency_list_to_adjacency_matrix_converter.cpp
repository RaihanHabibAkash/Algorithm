#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];

void adjacency_list_to_Adjacency_matrix_converter(int adj_mat[][100], int nodes) {
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < adj_list[i].size(); j++) { 
            adj_mat[i][adj_list[i][j]] = 1;
            adj_mat[adj_list[i][j]][i] = 1;
        }
        
        /* can use range base for loop
        for(int i = 0; i < nodes; i++) {
            for(int val : adj_list[i]) {
                adj_mat[i][val] = 1;
                adj_mat[val][i] = 1;
            }
        }
        */
    }

}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int adj_mat[100][100];
    memset(adj_mat, 0, sizeof(adj_mat));

    adjacency_list_to_Adjacency_matrix_converter(adj_mat, nodes);

    // print
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++)
            cout << adj_mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}