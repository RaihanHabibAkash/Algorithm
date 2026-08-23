// Problem: Dijkstra Algorithm
// Platform: Geek For Geeks
// Difficulty: Medium
// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Topics: Path relaxion for optimized Dijkstra

/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w weight.
Find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
Constraints:
1 ≤ V ≤ 106
1 ≤ E = edges.size() ≤ 106
0 ≤ edges[i][0], edges[i][1] ≤ V-1
0 ≤ edges[i][2] ≤ 104
0 ≤ src < V
*/

class Solution {
  public:
    int dis[1000005];
    
    class cmp {
    public:
        bool operator()(pair<int,int> l, pair<int,int> r) {
            return l.second > r.second;
        }
    };
    
    void dijkstra(vector<vector<pair<int,int>>> &adj_list, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        pq.push({src, 0});
        dis[src] = 0;
        
        while(!pq.empty()) {
            int par_node = pq.top().first,
                par_dis = pq.top().second;
            pq.pop();
            
            if(par_dis > dis[par_node]) continue;
            
            for(pair<int,int> child : adj_list[par_node]) {
                int child_node = child.first,
                    child_dis = child.second;
                    
                if(par_dis + child_dis < dis[child_node]) {
                    dis[child_node] = par_dis + child_dis;
                    pq.push({child_node, dis[child_node]});
                }
            }
        }
    }
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj_list(V);
        for(int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj_list[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        for(int i = 0; i < V; i++)
            dis[i] = INT_MAX;
            
        dijkstra(adj_list, src);
        vector<int> ans;
        for(int i = 0; i < V; i++)
            ans.push_back(dis[i]);
        return ans;
    }
};