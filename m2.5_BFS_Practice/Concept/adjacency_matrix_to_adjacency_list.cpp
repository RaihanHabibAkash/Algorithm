#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];

void adj_matrix_to_adj_list_converter(int adj_mat[][100], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj_mat[i][j] == 1)
                adj_list[i].push_back(j);
}

int main() {
    int adj_mat[100][100];
    int n; cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj_mat[i][j];
    
    adj_matrix_to_adj_list_converter(adj_mat, n);

    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";
        cout << endl;
    }

    return 0;
}