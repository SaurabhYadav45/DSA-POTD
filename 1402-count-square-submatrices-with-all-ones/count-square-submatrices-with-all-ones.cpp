class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(i >= m || j >= n)  return 0;
        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(i+1, j, matrix, dp);
        int right = solve(i, j+1, matrix, dp);
        int diagonal = solve(i+1, j+1, matrix, dp);
        return dp[i][j]=  1 + min({down, right, diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int result = 0;

        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result += solve(i, j, matrix, dp);
            }
        }
        return result;
    }
};


//                              METHOD-2 
//                              BOTTOM UP

// class Solution {
// public:
//     int m, n;
//     int countSquares(vector<vector<int>>& matrix) {
//         m = matrix.size();
//         n = matrix[0].size();
//         int result = 0;

//         vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 // Base case
//                 if(i == 0 || j == 0){
//                     dp[i][j] = matrix[i][j];
//                 }
//                 else if(matrix[i][j] == 1){
//                     dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
//                 }
//                 result += dp[i][j];
//             }
//         }
//         return result;
//     }
// };