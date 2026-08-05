// Problem: Undirected Graph Cycle
// Platform: Geek For Geeks
// Difficulty: Medium
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Topics: Undirectected Graph Cycle ditection

/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V
*/

class Solution {
  public:
    
    bool vis[100005];
    int par[100005];
    vector<int> adj_list[100005];
    
    bool dfs(int src) {
        vis[src] = true;
        
        for(int child : adj_list[src]) {
            // Got cycle
            if(vis[child] && child != par[src]) return true;
            
            if(!vis[child]) {
                par[child] = src;
                if(dfs(child)) 
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        memset(vis, false, sizeof(vis));
        memset(par, -1, sizeof(par));
        
        for(int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i < V; i++)
            if(!vis[i])
                if(dfs(i)) 
                    return true;
                
        return false;
    }
};