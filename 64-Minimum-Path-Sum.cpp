class Solution {
public:
    int findMinPath(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& dp) {
        if(i == n && j == m)
            return grid[i][j];
        if(i > n || j > m)
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];
        

        int down = findMinPath(grid, n, m, i+1, j, dp);
        int right = findMinPath(grid, n, m, i, j+1, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    } 

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return findMinPath(grid, n-1, m-1, 0, 0, dp);   
    }
};