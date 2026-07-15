#include <bits/stdc++.h>
using namespace std;

void adj_mat_to_adj_list_converter(int adj_mat[][100], int n) {
    vector<int> adj_list[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj_mat[i][j] == 1) adj_list[i].push_back(j);
            
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adj_list[i].size(); j++) // we can use range base for loop
            cout << adj_list[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n; cin >> n;
    int adj_mat[100][100];
    memset(adj_mat, 0, sizeof(adj_mat));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj_mat[i][j];

    adj_mat_to_adj_list_converter(adj_mat, n);

    return 0;
}