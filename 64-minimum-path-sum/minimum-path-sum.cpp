class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        //Initialization
        dp[0][0] = grid[0][0];
        for(int i=1; i<m; i++){
            dp[i][0] += grid[i][0] + dp[i-1][0];
        }

        for(int j=1; j<n; j++){
            dp[0][j] += grid[0][j] + dp[0][j-1];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int down = dp[i-1][j];
                int right = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(down, right);
            }
        }
        return dp[m-1][n-1];
    }
};



// class Solution {
// public:
//     int m, n;
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
//         if(i >= m || j >= n) return 1e9;
//         if(i == m-1 && j == n-1) return grid[m-1][n-1];

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int down = grid[i][j] + solve(i+1, j, grid, dp);
//         int right = grid[i][j] + solve(i, j+1, grid, dp);
//         return dp[i][j] = min(down , right);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         vector<vector<int>>dp(m, vector<int>(n, -1));
//         return solve(0, 0, grid, dp);
//     }
// };