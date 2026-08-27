#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;

    Edge(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main() {
    int nodes, edges; cin >> nodes >> edges;
    vector<Edge> edge_list;
    int dis[1005];

    while(edges--) {
        int a,b,c; cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    for(int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;
    dis[0] = 0; // src will be 0 always(0 is src in this one)

    // Edge relaxation n-1 times
    for(int i = 1; i <= nodes-1; i++) {
        for(auto ed : edge_list) {
            int a = ed.a,
                b = ed.b,
                c = ed.c;

            if(dis[a] != INT_MAX && dis[a]+c < dis[b])
                dis[b] = dis[a] + c;
        }
    }
    // Extra 1 time for cycle detection
    bool cycle = false;
    for(auto ed : edge_list) {
            int a = ed.a,
                b = ed.b,
                c = ed.c;

            if(dis[a] != INT_MAX && dis[a]+c < dis[b]) {
                cycle = true;
                break;
            }
    }

    if(cycle) cout << "Negative Cycle" << endl;
    else 
        for(int i = 0; i < nodes; i++)
            cout << i << " -> " << dis[i] << endl;
    

    return 0;
}
/*
    In negative cyclic graph dont have ans. it relax edges every time
    If no Cycle:
                0 2 5
                0 3 12
                2 1 2
                1 3 3
*/