// Problem: Bellman Ford
// Platform: Geek For Geeks
// Difficulty: Medium
// Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Topics: Bellman Ford
/*
Given a weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Compute the shortest distances from the src to all other vertices. If a vertex is unreachable from the src, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Examples:

Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0

Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 -> 1
For 0 to 2 minimum distance will be 6. By following path 0 -> 1 -> 2
For 0 to 3 minimum distance will be 6. By following path 0 -> 1 -> 2 -> 4 -> 3 
For 0 to 4 minimum distance will be 7. By following path 0 -> 1 -> 2 -> 4
Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0

Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 -> 2 -> 3 -> 1, where the total weight of the cycle is negative.
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ V*(V-1)
-1000 ≤ w ≤ 1000
0 ≤ src < V
*/
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, mxDis);
        dis[src] = 0;
        
        for(int k = 1; k <= V-1; k++)
            for(int i = 0; i < edges.size(); i++) {
                int a = edges[i][0], // a ---cost--> b
                    b = edges[i][1],
                    cost = edges[i][2];

                if(dis[a] != 1e8 && dis[a] + cost < dis[b])
                    dis[b] = dis[a] + cost;
            }
            
        // Cycle deted return direcly
        for(int i = 0; i < edges.size(); i++) {
                int a = edges[i][0], // a ---cost--> b
                    b = edges[i][1],
                    cost = edges[i][2];

                if(dis[a] != 1e8 && dis[a] + cost < dis[b])
                    return {-1};
        }
        
        return dis;
    }
};