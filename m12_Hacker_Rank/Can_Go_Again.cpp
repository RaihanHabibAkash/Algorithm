/*

You will be given  numbers of nodes,  numbers of edges in a graph. For each edge you will be given ,  and  which means there is a connection from  to  only and for which you need to give  cost. The value of nodes could be from  to .

You will be given a source node . Then you will be given a test case , for each test case you will be given a destination node . You need to tell the minimum cost from source node to destination. If there is no possible path from  to  then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

Input Format

First line will contain  and .
Next  lines will contain ,  and .
Next line will contain source node .
Next line will contain , the number of test cases.
For each test case, you will get .
Constraints

Output Format

Output the minimum cost for each test case.
Sample Input 0

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5
Sample Output 0

0
-1
-2
-5
0
Sample Input 1

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5
Sample Output 1

Not Possible
Not Possible
Not Possible
Not Possible
0
Sample Input 2

5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5
Sample Output 2

Negative Cycle Detected
*/
// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/can-go-again/problem
#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> edge_list;
long long dis[1005];

bool bellman_ford(int src, int nodes) {
    dis[src] = 0;

    for(int i = 1; i <= nodes-1; i++)
        for(auto [a, b, c] : edge_list)
            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;

    for(auto [a, b, c] : edge_list)
            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                return true; // cycle detected
    return false; // no cycle
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    for(int i = 1; i <= nodes; i++)
        dis[i] = LLONG_MAX;

    while(edges--) {
        long long a, b, c; cin >> a >> b >> c;
        edge_list.push_back({a, b, c});
    }

    int src; cin >> src;
    if(bellman_ford(src, nodes))
        cout << "Negative Cycle Detected" << endl;
    else {
        int cs; cin >> cs;
        while(cs--) {
            int dst; cin >> dst;
            if(dis[dst] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[dst] << endl;
        }
    }

    return 0;
}