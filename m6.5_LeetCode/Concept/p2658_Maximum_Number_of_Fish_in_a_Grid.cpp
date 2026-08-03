// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

class Solution {
public:
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
            return 0;
        int sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(grid, i+1, j);
        sum += dfs(grid, i-1, j);
        sum += dfs(grid, i, j+1);
        sum += dfs(grid, i, j-1);

        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int mx = 0;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] > 0) 
                    mx = max(mx, dfs(grid, i, j));

        return mx;
    }
};