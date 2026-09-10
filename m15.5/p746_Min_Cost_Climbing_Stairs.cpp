// Problem: Min Cost Climbing Stairs
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Topics: 0-1 KnapSack
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.

Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the staircase, which is the position just past the last step (index cost.length).

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/
class Solution {
public:
    int dp[1005];

    int stps(vector<int>& cost, int n, int i) {
        if(i == n)
            return 0;
        else if(i == n-1)
            return cost[i];

        if(i >= 0 && dp[i] != -1)
            return dp[i];
        
        int option1 = stps(cost, n, i+1),
            option2 = stps(cost, n, i+2);

        if(i >= 0)
            return dp[i] = min(option1, option2) + cost[i];
        else
            return min(option1, option2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));

        return stps(cost, n, -1);
    }
};