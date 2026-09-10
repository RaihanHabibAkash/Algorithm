// Problem: Pascal's Triangle
// Platform: LeetCode
// Difficulty: Easy
// Link: https://leetcode.com/problems/pascals-triangle/
// Topics: Dynamic Programming bottom-up(Tabulation), Recurtion Backtracking
/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/
class Solution {
public:
    vector<vector<int>> ans;

    vector<int> rec(int i) {
        if (i == 1)
            return {1};

        vector<int> prevRow = rec(i - 1);
        ans.push_back(prevRow);

        vector<int> newRow;
        newRow.push_back(1);
        for (int i = 1; i < prevRow.size(); i++)
            newRow.push_back(prevRow[i - 1] + prevRow[i]);
        newRow.push_back(1);

        return newRow;
    }

    vector<vector<int>> generate(int numRows) {
        ans.push_back(rec(numRows));
        return ans;
    }
};