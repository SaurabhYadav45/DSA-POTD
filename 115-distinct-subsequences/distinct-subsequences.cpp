class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>&dp){
        if(j == 0) return 1; 
        if(i == 0) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int take = 0;
        if(s[i-1] == t[j-1]){
            take = solve(i-1, j-1, s, t, dp);
        }

        int skip = solve(i-1, j, s, t, dp);
        long long ways = take + skip;
        return dp[i][j] = ways;
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(n > m) return 0;
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m+1; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                long long ways = 0;
                int take = 0;
                if(s[i-1] == t[j-1]){
                    take = dp[i-1][j-1];
                }
                int skip = dp[i-1][j];
                ways = (long long)take + skip;
                dp[i][j] = ways;
            }
        }
        return dp[m][n];
    }
};


// class Solution {
// public:
//     int solve(int i, int j, string& s, string& t, vector<vector<int>>&dp){
//         if(j == 0) return 1; 
//         if(i == 0) return 0;

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int take = 0;
//         if(s[i-1] == t[j-1]){
//             take = solve(i-1, j-1, s, t, dp);
//         }

//         int skip = solve(i-1, j, s, t, dp);
//         long long ways = take + skip;
//         return dp[i][j] = ways;
//     }
//     int numDistinct(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         if(n > m) return 0;
//         vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
//         return solve(m, n, s, t, dp);
//     }
// };


// class Solution {
// public:
//     int solve(int i, int j, string& s, string& t, vector<vector<int>>&dp){
//         if(j == t.size()) return 1; 
//         if(i == s.size()) return 0;

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int take = 0;
//         if(s[i] == t[j]){
//             take = solve(i+1, j+1, s, t, dp);
//         }

//         int skip = solve(i+1, j, s, t, dp);
//         long long ways = take + skip;
//         return dp[i][j] = ways;
//     }
//     int numDistinct(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         if(n > m) return 0;
//         vector<vector<int>>dp(m, vector<int>(n, -1));
//         return solve(0, 0, s, t, dp);
//     }
// };


// class Solution {
// public:
//     int solve(int i, string&curr, string& s, string& t){
//         if(i >= s.size()){
//             if(curr == t) return 1;
//             return 0;
//         }
//         // take
//         curr.push_back(s[i]);
//         int take = solve(i+1, curr, s, t);
//         curr.pop_back(); // backtrack
//         // skip
//         int skip = solve(i+1, curr, s, t);

//         return take + skip;
//     }
//     int numDistinct(string s, string t) {
//         int n = s.length();
//         string curr = "";
//         return solve(0, curr, s, t);
//     }
// };