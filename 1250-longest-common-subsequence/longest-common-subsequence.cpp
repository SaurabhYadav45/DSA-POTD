class Solution {
public:
    int m, n;
    int solve(int m, int n, string& s1, string& s2, vector<vector<int>>&dp){
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        // Match
        if(s1[m] == s2[n]){
            return 1 + solve(m-1, n-1, s1, s2, dp);
        }
        // Didn't match
        int case1 = solve(m-1, n, s1, s2, dp);
        int case2 = solve(m, n-1, s1, s2, dp);
        return dp[m][n] = max(case1, case2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, text1, text2, dp);
    }
};



// class Solution {
// public:
//     int solveUsingRecursion(string text1, string text2, int i, int j){
//         // Base case
//         if(i >= text1.length()) return 0;
//         if(j >= text2.length()) return 0;

//         int  ans =0;
//         if(text1[i] == text2[j]){
//             ans = 1 + solveUsingRecursion(text1, text2, i+1, j+1);
//         }
//         else{
//             ans = max(solveUsingRecursion(text1, text2, i+1, j), 
//                      solveUsingRecursion(text1, text2, i, j+1));
//         }
//         return ans;
//     }

//     int solveUsingMemo(string& text1, string& text2, int i, int j, vector<vector<int>>&dp){
//         // Base case
//         if(i >= text1.length()) return 0;
//         if(j >= text2.length()) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int  ans =0;
//         if(text1[i] == text2[j]){
//             ans = 1 + solveUsingMemo(text1, text2, i+1, j+1, dp);
//         }
//         else{
//             ans = max(solveUsingMemo(text1, text2, i+1, j, dp), 
//                      solveUsingMemo(text1, text2, i, j+1, dp));
//         }
//         dp[i][j] = ans;
//         return dp[i][j];
//     }

//     // int solveUsingTabulation(string& text1, string& text2, int i, int j){
//     //     vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, 0));

//     //     for(int i = text1.length()-1; i >= 0; i--){
//     //         for(int j= text2.length()-1; j >= 0; j--){

//     //             int ans = 0;
//     //             if(text1[i] == text2[j]){
//     //                 ans = 1 + dp[i+1][j+1];
//     //             }
//     //             else{
//     //                 ans = max(dp[i+1][j], dp[i][j+1]);
//     //             }
//     //             dp[i][j] = ans;
//     //         }
//     //     }
//     //     return dp[0][0];
//     // }

//     int solveUsingTabulation(string& text1, string& text2, int i, int j){
//         int m = text1.length();
//         int n = text2.length();

//         vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

//         for(int i=1; i<=m; i++){
//             for(int j=1; j<=n; j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }

//         // Print the longest common subsequence
//         // string ans = "";
//         // int i=m, j=n; 
//         // while(i >0 && j>0){
//         //     if(text1[i-1] == text2[j-1]){
//         //         ans.push_back(text1[i-1]);
//         //         i--;
//         //         j--;
//         //     }
//         //     else{
//         //         if(dp[i][j-1] > dp[i-1][j]){
//         //             j--;
//         //         }else{
//         //             i--;
//         //         }
//         //     }
//         // }
//         // reverse(ans.begin(), ans.end());
//         // cout<<ans<<endl;

//         return dp[m][n];
//     }

//     int solveUsingTabulationSO(string& text1, string& text2, int i, int j){
//         vector<int>curr(text1.length()+1, 0);
//         vector<int>next(text1.length()+1, 0);
//         for(int j = text2.length()-1; j >=0; j--){
//             for(int i=text1.length()-1; i >= 0; i--){
//                 int ans = 0;
//                 if(text1[i] == text2[j]){
//                     ans = 1 + next[i+1];
//                 }
//                 else{
//                     ans = max(next[i], curr[i+1]);
//                 }
//                 curr[i] = ans;
//             }
//             next = curr;
//         }
//         return next[0];
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int i=0;
//         int j=0;
//         vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
//         // int ans = solveUsingRecursion(text1, text2, i, j);
//         // int ans = solveUsingMemo(text1, text2, i, j, dp);
//         int ans = solveUsingTabulation(text1, text2, i, j);
//         // int ans = solveUsingTabulationSO(text1, text2, i, j);
//         return ans;
//     }
// };