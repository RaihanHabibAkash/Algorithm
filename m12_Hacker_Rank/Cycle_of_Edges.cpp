/*
You will be given an undirected graph where there will be  nodes and  edges. You need to tell the number of edges that can create a cycle in the graph.

Note: Duplicate edges as input can not be possible. The value of nodes are from  to .

Input Format

First line will contain  and .
Next  lines will contain  and  which means there is a edge between  and .
Constraints

Output Format

Output the number of edges that can create a cycle.
Sample Input 0

5 7
1 2
2 3
3 4
4 5
4 1
2 4
5 3
Sample Output 0

3
Sample Input 1

3 3
1 2
2 3
1 3
Sample Output 1

1
*/
// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/cycle-of-edges/

#include <bits/stdc++.h>
using namespace std;

int leader[100000 + 100];
int grp_size[100000 + 100];

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
    int nodes, edges; cin >> nodes >> edges;

    // Setting the array's default value
    for(int i = 1; i <= nodes; i++) {
        leader[i] = -1;
        grp_size[i] = 1;
    }

    int cycles = 0;
    while(edges--) {
        int a, b; cin >> a >> b;
        
        int l1 = dsu_find(a),
            l2 = dsu_find(b);

        if(l1 == l2)
            cycles++;
        else
            dsu_union(l1, l2);
    }

    cout << cycles << endl;

    return 0;
}