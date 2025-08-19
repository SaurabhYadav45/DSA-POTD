    //  **************** Approach : 1 => Rec + Memo ***************

class Solution {
public:
    int n;
    int solve(int i, int j, string& s, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = 2 + solve(i+1, j-1, s, dp);
        }
        else{
            int case1 = solve(i, j-1, s, dp);
            int case2 = solve(i+1, j, s, dp);
            return dp[i][j] = max(case1, case2);
        }
    }
    int longestPalindromeSubseq(string s) {
        n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, dp);
    }
};


//       *************** Approach : 1 => Tabulation ****************

// class Solution {
// public:
//     int n;
//     int solve(int i, int j, string& s1, string& s2){
//         vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

//         for(int i=1; i<n+1; i++){
//             for(int j=1; j<n+1; j++){
//                 if(s1[i-1] == s2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
//         return dp[n][n];
//     }
//     int longestPalindromeSubseq(string s) {
//         n = s.size();
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
//         return solve(n, n, s1, s2);
//     }
// };


//      **************** Approach : 1 => Rec + Memo ***************

// class Solution {
// public:
//     int solve(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
//         if(i == 0 || j == 0){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(s1[i-1] == s2[j-1]){
//             return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
//         }
//         else{
//             int case1 = solve(i, j-1, s1, s2, dp);
//             int case2 = solve(i-1, j, s1, s2, dp);
//             return dp[i][j] = max(case1, case2);
//         }
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
//         vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         return solve(n, n, s1, s2, dp);
//     }
// };



// class Solution {
// public:
//     int solveUsingRec(string& a, string& b, int i, int j , vector<vector<int>>&dp){
//         if(i >= a.length()) return 0;
//         if(j >= b.length()) return 0;

//         if(dp[i][j] != -1) return dp[i][j];
        
//         int ans = 0;
//         if(a[i] == b[j]){
//             ans = 1 + solveUsingRec(a, b, i+1, j+1, dp);
//         }
//         else{
//             ans = max(solveUsingRec(a, b, i, j+1, dp), solveUsingRec(a, b, i+1, j, dp));
//         }
//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     int solveUsingTabulation(string& a, string& b, int i, int j){
//         vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 0));

//         for(int j = b.length()-1; j>=0; j--){
//             for(int i= a.length()-1; i >=0; i--){
//                 int ans = 0;
//                 if(a[i] == b[j]){
//                     ans = 1 + dp[i+1][j+1];
//                 }
//                 else{
//                     ans = max(dp[i+1][j], dp[i][j+1]);
//                 }
//                 dp[i][j] = ans;
//             }
//         }
//         return dp[0][0];
//     }

//     int longestPalindromeSubseq(string s) {
//         int i=0;
//         int j =0;
//         string rs = s;
//         reverse(rs.begin(), rs.end());

//         // vector<vector<int>>dp(s.length()+1, vector<int>(rs.length()+1, -1));
//         // int ans   = solveUsingRec(s, rs, i, j, dp);
//         int ans   = solveUsingTabulation(s, rs, i, j);
//         return ans;
//     }
// };