class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        // Initialization
        dp[n][0] = dp[n][1] = 0;
        int buy = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                if(j){
                    int take = -prices[i] + dp[i+1][0];
                    int skip = dp[i+1][1];
                    dp[i][j] = max(take, skip);
                }
                else{
                    // sell
                    int take = prices[i] + dp[i+1][1];
                    int skip = dp[i+1][0];
                    dp[i][j] = max(take, skip);
                }
            }
        }
        return dp[0][1];
    }
};


// class Solution {
// public:
//     int solve(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
//         if(i >= prices.size()){
//             return 0;
//         }

//         if(dp[i][buy] != -1){
//             return dp[i][buy];
//         }

//         if(buy){
//             int take = -1*prices[i] + solve(i+1, 0, prices, dp);
//             int skip = solve(i+1, 1, prices, dp);
//             return dp[i][buy] = max(take, skip);
//         }
//         else{
//             // sell
//             int take = prices[i] + solve(i+1, 1, prices, dp);
//             int skip = solve(i+1, 0, prices, dp);
//             return dp[i][buy] = max(take, skip);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>>dp(n, vector<int>(2, -1));
//         return solve(0, 1, prices, dp);
//     }
// };