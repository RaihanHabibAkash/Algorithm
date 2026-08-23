// Problem: Number of Provinces
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/network-delay-time/
// Topics: Weighted DAG, Dijkstra

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

class Solution {
public:
    int dis[105];
    vector<pair<int,int>> adj_list[105];

    void dijkstra(int src) {
        priority_queue<pair<int,int>> pq;
        dis[src] = 0;
        pq.push({src, 0});

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

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i = 1; i <= n; i++)
            dis[i] = INT_MAX;
        for(int i = 0; i < times.size(); i++)
            adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
        
        dijkstra(k);

        for(int i = 1; i <= n; i++)
            if(dis[i] == INT_MAX) return -1;
        
        int val = -1;
        for(int i = 1; i <= n; i++)
            if(dis[i] > val)
                val = dis[i];

        return val;
    }
};