class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(i >= m || j >= n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(i+1, j, obstacleGrid, dp);
        int right = solve(i, j+1, obstacleGrid, dp);
        int totalPath = down + right;
        return dp[i][j] = totalPath;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};