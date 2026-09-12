// Problem: Coin Change II
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/coin-change-ii/
// Topics: Unbounded KnapSack
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/
class Solution {
public:
    int dp[305][5005];

    int unbounded_knapSack(vector<int>& coins, int i, int amount) {
        if(amount == 0) return 1;
        else if(i < 0) return 0;
        
        if(dp[i][amount] != -1) return dp[i][amount];

        int option1 = 0;
        if(coins[i] <= amount)
            option1 = unbounded_knapSack(coins, i, amount - coins[i]);

        return dp[i][amount] = option1 + unbounded_knapSack(coins, i-1, amount);
    }

    int change(int amount, vector<int>& coins) {
        for(int i = 0; i <= coins.size(); i++)
            for(int j = 0; j <= amount; j++)
                dp[i][j] = -1;

        return unbounded_knapSack(coins, coins.size()-1, amount);
    }
};