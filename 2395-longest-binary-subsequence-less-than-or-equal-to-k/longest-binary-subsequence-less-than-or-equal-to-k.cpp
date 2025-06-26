class Solution {
private:
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int length = 0;
        int powerValue = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                length++;
            }
            else if(powerValue <= k){
                length++;
                k = k-powerValue;
            }
            
            if(powerValue <= k){
                powerValue = powerValue << 1;
            }
        }
        return length;
    }
};





// //                                   DP Memoization
// class Solution {
// public:
//     int n;
//     int solve(int idx, string&s, int k, vector<vector<int>>&dp){
//         if(idx < 0) return 0;

//         if(dp[idx][k] != -1){
//             return dp[idx][k];
//         }

//         long long val = (s[idx] - '0') * powl(2, n-idx-1);
//         // take
//         int take = 0;
//         if(val <= k){
//             take = 1 + solve(idx-1, s, k-val, dp);
//         }
//         // skip
//         int skip = solve(idx-1, s, k, dp);

//         // take maximum of both
//         int maxLength = max(take, skip);
//         return dp[idx][k] = maxLength ;
//     }
//     int longestSubsequence(string s, int k) {
//         n = s.length();
//         vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
//         return solve(n-1, s, k, dp);
//     }
// };





//                           simple recursion

// class Solution {
// public:
//     int n;
//     int solve(int idx, string&s, int k){
//         if(idx < 0) return 0;

//         long long val = (s[idx] - '0') * powl(2, n-idx-1);
//         // take
//         int take = 0;
//         if(val <= k){
//             take = 1 + solve(idx-1, s, k-val);
//         }
//         // skip
//         int skip = solve(idx-1, s, k);

//         // take maximum of both
//         int maxLength = max(take, skip);
//         return maxLength;
//     }
//     int longestSubsequence(string s, int k) {
//         n = s.length();
//         return solve(n-1, s, k);
//     }
// };