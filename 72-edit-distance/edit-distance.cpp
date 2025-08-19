class Solution {
public:
    int m, n;
    int solve(int i, int j, string& s1, string& s2){
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        // dp[i][j] = Minimum no. of operations required for making s1 of length i & s2 of length j equal
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i + j;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        return solve(m, n, word1, word2);
    }
};


//        ******************* Rec + Memo *******************

// class Solution {
// public:
//     int m, n;
//     int solve(int i, int j, string& word1, string& word2, vector<vector<int>>&dp){
//         if(i == 0 || j == 0){
//             return i+j;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(word1[i-1] == word2[j-1]){
//             return solve(i-1, j-1, word1, word2, dp);
//         }

//         int insert = 1 + solve(i, j-1, word1, word2, dp);
//         int deletes = 1 + solve(i-1, j, word1, word2, dp);
//         int replace = 1 + solve(i-1, j-1, word1, word2, dp);
//         return dp[i][j] = min({insert, deletes, replace});
//     }
//     int minDistance(string word1, string word2) {
//         m = word1.length();
//         n = word2.length();
//         vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
//         return solve(m, n, word1, word2, dp);
//     }
// };

//     int solveUsingRec(string &word1, string &word2, int i, int j){
//         int ans = 0;
//         if(i>=word1.length()){
//             return word2.length()-j;
//         }
//         if(j>=word2.length()){
//             return word1.length()-i;
//         }

//         if(word1[i] == word2[j]){
//             ans = 0 + solveUsingRec(word1, word2, i+1, j+1);
//         }
//         else{
//             int opt1 = 1 + solveUsingRec(word1, word2, i, j+1);    //Insert a character
//             int opt2 = 1 + solveUsingRec(word1, word2, i+1, j);    //Remove a character
//             int opt3 = 1 + solveUsingRec(word1, word2, i+1, j+1);  //Replace a character

//             ans = min(opt1, min(opt2, opt3));
//         }
//         return ans ;
//     }

//     int solveUsingMemo(string &word1, string &word2, int i, int j, vector<vector<int>>&dp){
//         int ans = 0;
//         if(i>=word1.length()){
//             return word2.length()-j;
//         }
//         if(j>=word2.length()){
//             return word1.length()-i;
//         }

//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i] == word2[j]){
//             ans = 0 + solveUsingMemo(word1, word2, i+1, j+1, dp);
//         }
//         else{
//             int opt1 = 1 + solveUsingMemo(word1, word2, i, j+1, dp);    //Insert a character
//             int opt2 = 1 + solveUsingMemo(word1, word2, i+1, j, dp);    //Remove a character
//             int opt3 = 1 + solveUsingMemo(word1, word2, i+1, j+1, dp);  //Replace a character

//             ans = min(opt1, min(opt2, opt3));
//         }
//         dp[i][j] = ans;
//         return dp[i][j]; ;
//     }

//     // int solveUsingTabulation(string &word1, string &word2, int i, int j){
//     //     vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));

//     //     for(int row =0; row <= word1.length(); row++){
//     //         dp[row][word2.length()] = word1.length()-row;
//     //     }

//     //     for(int col = 0; col <= word2.length(); col++){
//     //         dp[word1.length()][col] = word2.length()-col;
//     //     }

//     //     for(int i = word1.length()-1; i>=0; i--){
//     //         for(int j = word2.length()-1; j >=0; j--){
            
//     //             int ans = 0;
//     //             if(word1[i] == word2[j]){
//     //                 ans = 0 + dp[i+1][j+1];
//     //             }
//     //             else{
//     //                 int opt1 = 1 + dp[i][j+1];
//     //                 int opt2 = 1 + dp[i+1][j];
//     //                 int opt3 = 1 + dp[i+1][j+1];

//     //                 ans = min(opt1, min(opt2, opt3));
//     //             }
//     //             dp[i][j] = ans;
//     //         }
//     //     }
//     //     return dp[0][0];
//     // }

//     int solveUsingTabulation(string &a, string &b, int m, int n){
//         vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, -1));
//         for(int i=0; i<=m; i++){
//             for(int j=0; j<= n; j++){
//                 if(i == 0 || j == 0){
//                     dp[i][j] = i + j;
//                 }
//                 else if(a[i-1] == b[j-1]){
//                     dp[i][j] = dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
//                 }
//             }
//         }
//         return dp[m][n];
//     }

//     int minDistance(string word1, string word2) {
//         int ans = 0;
//         int i=0;
//         int j= 0;
//         vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
//         // ans = solveUsingRec(word1, word2, i, j);
//         // ans = solveUsingMemo(word1, word2, i, j, dp);
//         // ans = solveUsingTabulation(word1, word2, i, j);
//         ans = solveUsingTabulation(word1, word2, word1.length(), word2.length());
//         return ans;
//     }
// };