// Problem: Commandos
// Platform: LightOJ
// Link: https://lightoj.com/problem/commandos
/*
A group of commandos were assigned a critical task. They are to destroy an enemy headquarter. The enemy head quarter consists of several buildings and the buildings are connected by roads. The commandos must visit each building and place a bomb at the base of each building. They start their mission at the base of a particular building and from there they disseminate to reach each building. The commandos must use the available roads to travel between buildings. Any of them can visit one building after another, but they must all gather at a common place when their task in done. In this problem, you will be given the description of different enemy headquarters. Your job is to determine the minimum time needed to complete the mission. Each commando takes exactly one unit of time to move between buildings. You may assume that the time required to place a bomb is negligible. Each commando can carry unlimited number of bombs and there is an unlimited supply of commando troops for the mission.

Input
Input starts with an integer T (≤50), denoting the number of test cases.

The first line of each case starts with a positive integer N (1 ≤ N ≤ 100), where N denotes the number of buildings in the headquarter. The next line contains a positive integer R, where R is the number of roads connecting two buildings. Each of the next R lines contain two distinct numbers u v (0 ≤ u, v < N), this means there is a road connecting building u to building v. The buildings are numbered from 0 to N-1. The last line of each case contains two integers s d (0 ≤ s, d < N). Where s denotes the building from where the mission starts and d denotes the building where they must meet. You may assume that two buildings will be directly connected by at most one road. The input will be given such that, it will be possible to go from any building to another by using one or more roads.

Output
For each case, print the case number and the minimum time required to complete the mission.

Sample
Input	Output
2
4
3
0 1
2 1
1 3
0 3
2
1
0 1
1 0
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int src_to_node[105];
int dst_to_node[105];

void bfs(int src, bool flag) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    if(flag) src_to_node[src] = 0;
    else dst_to_node[src] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par])
            if(!vis[child]) {
                vis[child] = true;
                
                if(flag) src_to_node[child] = src_to_node[par] + 1;
                else dst_to_node[child] = dst_to_node[par] + 1;

                q.push(child);
            }
    }
}

int main() {
    int cs; cin >> cs;

    for(int t = 1; t <= cs; t++) {
        int nodes, edges; cin >> nodes >> edges;
        while(edges--) {
            int a,b; cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        int src, dst; cin >> src >> dst;

        // For src level
        memset(vis, false, sizeof(vis));
        memset(src_to_node, -1, sizeof(src_to_node));
        bfs(src, true);

        // For destination level
        memset(vis, false, sizeof(vis));
        memset(dst_to_node, -1, sizeof(dst_to_node));
        bfs(dst, false);

        int ans = -1;
        for(int i = 0; i < nodes; i++)
            if(src_to_node[i] + dst_to_node[i] > ans)
                ans = src_to_node[i] + dst_to_node[i];
        
        cout << "Case " << t << ": " << ans << endl;

        // Removing vector from each index of adjacency list
        for(int i = 0; i < nodes; i++)
            adj_list[i].clear();
    }

    return 0;
}