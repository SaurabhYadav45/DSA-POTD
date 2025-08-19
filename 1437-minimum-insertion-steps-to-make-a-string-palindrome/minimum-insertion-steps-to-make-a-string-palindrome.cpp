class Solution {
public:   
    int solve(int i, int j, string& s, vector<vector<int>>&dp){
        if(i >= j) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1, j-1, s, dp);
        }
        else{
            int case1 = solve(i+1, j, s, dp);
            int case2 = solve(i, j-1, s, dp);
            return dp[i][j] = 1 + min(case1, case2);
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};



// class Solution {
// public:
//     int solveUsingMemo(string& s, int i, int j, vector<vector<int>>&dp){
//         // Base case
//         if(i >= j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == s[j]){
//            return dp[i][j] = solveUsingMemo(s, i+1, j-1, dp);
//         }
//         return dp[i][j] =  1 + min(solveUsingMemo(s, i+1, j, dp), solveUsingMemo(s, i, j-1, dp));
//     }

//     int solveUsingTabulation(string& s){
//         int n = s.length();
//         vector<vector<int>>dp(n+1, vector<int>(n+1));
//         for(int i=0; i<=n; i++){
//             dp[i][i] = 0;
//         }

//         for(int L =2; L<=n; L++){
//             for(int i=0; i< n-L+1; i++){
//                 int j = i+L-1;
//                 if(s[i] == s[j]){
//                     dp[i][j] = dp[i+1][j-1];
//                 }
//                 else{
//                     dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
//                 }
//             }
//         }
//         return dp[0][n-1];
//     }
//     int minInsertions(string s) {
//         int n = s.length();
//         // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         // int ans = solveUsingMemo(s, 0, n-1, dp);
//         int ans = solveUsingTabulation(s);
//         return ans;
//     }
// };