/*
You'll be given a graph of  nodes and  edges. For each edge, you'll be given ,  and  which means there is an edge from  to  only and which will cost .

Also, you'll be given  queries, for each query you'll be given  and , where  is the source and  is the destination. You need to print the minimum cost from  to  for each query. If there is no connection between  and , print .

Note: There can be multiple edges from one node to another. Make sure you handle this one.

Input Format

First line will contain  and .
Next  lines will contain ,  and .
After that you'll get .
Next  queries will contain  and .
Constraints

Output Format

Output the minimum cost for each query.
Sample Input 0

4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2
Sample Output 0

7
4
6
4
5
3
Sample Input 1

4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2
Sample Output 1

4
6
8
2
4
6
*/
// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/shortest-distance-2/

#include <bits/stdc++.h>
using namespace std;

long long adj_mat[105][105]; // Adjacency Matrix

void floyd_warshall(int nodes) {
    for(int k = 1; k <= nodes; k++)
        for(int i = 1; i <= nodes; i++)
            for(int j = 1; j <= nodes; j++)
                if(adj_mat[i][k]!=LLONG_MAX && adj_mat[k][j]!=LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    // Setting the default values of matrix
    for(int i = 1; i <= nodes; i++)
        for(int j = 1; j <= nodes; j++) {
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }

    while(edges--) {
        long long a, b, c; cin >> a >> b >> c;

        if(c < adj_mat[a][b])
            adj_mat[a][b] = c;
    }

    floyd_warshall(nodes);

    int queries; cin >> queries;
    while(queries--) {
        int src, dst; cin >> src >> dst;

        if(adj_mat[src][dst] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][dst] << endl;
    }

    return 0;
}