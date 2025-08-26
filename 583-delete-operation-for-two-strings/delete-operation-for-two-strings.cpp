class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
        if(i == 0 || j == 0){
            return i + j;
        }
 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int case1 = 1e9;
        if(s1[i-1] == s2[j-1]){
            case1 = solve(i-1, j-1, s1, s2, dp);
        }
        int case2 = 1 + solve(i-1, j, s1, s2, dp);
        int case3 = 1 + solve(i, j-1, s1, s2, dp);
        return dp[i][j] = min({case1, case2, case3});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i+j;
                }
            }
        }
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                int case1 = 1e9;
                if(word1[i-1] == word2[j-1]){
                    case1 = dp[i-1][j-1];
                }
                int case2 = 1 + dp[i-1][j];
                int case3 = 1 + dp[i][j-1];
                dp[i][j] = min({case1, case2, case3});
            }
        }
        return dp[m][n];
    }
};


// class Solution {
// public:
//     int m, n;
//     int solve(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
//         if(i == 0 || j == 0){
//             return i + j;
//         }
 
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int case1 = 1e9;
//         if(s1[i-1] == s2[j-1]){
//             case1 = solve(i-1, j-1, s1, s2, dp);
//         }
//         int case2 = 1 + solve(i-1, j, s1, s2, dp);
//         int case3 = 1 + solve(i, j-1, s1, s2, dp);
//         return dp[i][j] = min({case1, case2, case3});
//     }
//     int minDistance(string word1, string word2) {
//         m = word1.size();
//         n = word2.size();
//         vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
//         return solve(m, n, word1, word2, dp);
//     }
// };



// class Solution {
// public:
//     int m, n;
//     int solve(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
//         if(i >= m) return n-j;
//         if(j >= n) return m-i;
 
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int case1 = 1e9;
//         if(s1[i] == s2[j]){
//             case1 = solve(i+1, j+1, s1, s2, dp);
//         }
//         int case2 = 1 + solve(i+1, j, s1, s2, dp);
//         int case3 = 1 + solve(i, j+1, s1, s2, dp);
//         return dp[i][j] = min({case1, case2, case3});
//     }
//     int minDistance(string word1, string word2) {
//         m = word1.size();
//         n = word2.size();
//         vector<vector<int>>dp(m, vector<int>(n, -1));
//         return solve(0, 0, word1, word2, dp);
//     }
// };