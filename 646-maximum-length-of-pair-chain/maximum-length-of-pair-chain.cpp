class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int>dp(n, 1);
        int maxLIS =1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};


// class Solution {
// public:
//     int solve(int i, int prev, vector<vector<int>>& pairs, vector<vector<int>>&dp){
//         if(i >= pairs.size()){
//             return 0;
//         }

//         if(dp[i][prev+1] != -1){
//             return dp[i][prev+1];
//         }

//         int take = INT_MIN;
//         if(prev == -1 || pairs[i][0] > pairs[prev][1]){
//             take = 1 + solve(i+1, i, pairs, dp);
//         }
//         int skip = solve(i+1, prev, pairs, dp);
//         return dp[i][prev+1] = max(take, skip);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();
//         sort(pairs.begin(), pairs.end());
//         vector<vector<int>>dp(n, vector<int>(n+1, -1));
//         return solve(0, -1, pairs, dp);
//     }
// };