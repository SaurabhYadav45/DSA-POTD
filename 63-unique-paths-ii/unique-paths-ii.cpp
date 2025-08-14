class Solution {
public:
    int m, n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>>dp(m, vector<int>(n, 0));

        // Initialization
        dp[0][0] = 1;
        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
            }
            else if(obstacleGrid[i-1][0] == 1){
                dp[i][0] = 0;
                obstacleGrid[i][0] = 1; // Important line
            }
            else{
                dp[i][0] = 1;
            } 
        }

        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j] == 1){
                dp[0][j] = 0;
            }
            else if(obstacleGrid[0][j-1] == 1){
                dp[0][j] = 0;
                obstacleGrid[0][j] = 1; // Important line
            }
            else{
                dp[0][j] = 1;
            } 
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};


//                **************** Rec + Memo ***************

// class Solution {
// public:
//     int m, n;
//     int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
//         if(i >= m || j >= n || obstacleGrid[i][j] == 1){
//             return 0;
//         }
//         if(i == m-1 && j == n-1) return 1;

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int down = solve(i+1, j, obstacleGrid, dp);
//         int right = solve(i, j+1, obstacleGrid, dp);
//         int totalPath = down + right;
//         return dp[i][j] = totalPath;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         m = obstacleGrid.size();
//         n = obstacleGrid[0].size();
//         vector<vector<int>>dp(m, vector<int>(n, -1));
//         return solve(0, 0, obstacleGrid, dp);
//     }
// };