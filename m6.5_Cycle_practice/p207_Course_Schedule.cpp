// Problem: Course Schedule
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/course-schedule/
// Topics: Cycle Detection in Directed Graph using DFS
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique
*/

class Solution {
public:
    vector<int> adj_list[2005];
    bool vis[2005];
    bool pathVis[2005];
    bool cycle = false;

    void dfs(int src) {
        vis[src] = true;
        pathVis[src] = true;

        for(int child : adj_list[src]) {
            if(vis[child] && pathVis[child])
                cycle = true;

            if(!vis[child]) dfs(child);
        }
        pathVis[src] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int> v : prerequisites)
            adj_list[v[0]].push_back(v[1]);

        memset(vis, false, sizeof(vis));
        memset(pathVis, false, sizeof(pathVis));

        for(int i = 0; i < numCourses; i++)
            if(!vis[i]) dfs(i);

        return !cycle;
    }
};