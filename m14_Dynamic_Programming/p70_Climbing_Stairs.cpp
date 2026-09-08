// Problem: Climbing Stairs
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/climbing-stairs/
// Topics: DP(top-down), Fibonacci series
/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

class Solution {
public:
    int dp[50];

    int stps(int n) {
        if(n == 1 || n == 2)
            return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = stps(n - 1) + stps(n - 2);
    }

    int climbStairs(int n) {
        for(int i = 1; i <= n; i++)
            dp[i] = -1;

        return stps(n);    
    }
};