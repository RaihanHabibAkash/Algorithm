// Problem: Minimum Path Sum
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/minimum-path-sum/
// Topics: 0-1 KnapSack
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
class Solution {
public:
    int dp[205][205];

    int knapSack(vector<vector<int>>& grid, int i, int j) {
        if(i == 0 && j == 0)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];

        int option1 = INT_MAX,
            option2 = INT_MAX;
        
        if(i > 0)
            option1 = knapSack(grid, i-1, j) + grid[i][j];
        if(j > 0)
            option2 = knapSack(grid, i, j-1) + grid[i][j];
        return dp[i][j] = min(option1, option2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size(),
            m = grid[0].size();

        return knapSack(grid, n-1, m-1);
    }
};