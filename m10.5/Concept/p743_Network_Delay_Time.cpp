// Problem: Number of Provinces
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/network-delay-time/
// Topics: Weighted DAG, Floyd Warshall

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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[105][105];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = INT_MAX;
            }

        for(int i = 0; i < times.size(); i++) {
            int a = times[i][0],
                b = times[i][1],
                cost = times[i][2];

            if(cost < dis[a][b])
                dis[a][b] = cost;
        }

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX && dis[i][k] + dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k] + dis[k][j];

        int val = -1;
        for(int i = 1; i <= n; i++) {
            if(dis[k][i] == INT_MAX)
                return -1;

            if(dis[k][i] > val)
                val = dis[k][i];
        }

        return val;
    }
};