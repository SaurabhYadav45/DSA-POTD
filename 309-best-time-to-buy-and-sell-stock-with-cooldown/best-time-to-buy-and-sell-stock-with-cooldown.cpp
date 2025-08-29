class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        // Initialization
        // dp[n][buy] = 0
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    int take = -prices[i] + dp[i+1][0];
                    int skip = dp[i+1][1];
                    dp[i][buy] = max(take, skip);
                }
                else{
                    int sell = prices[i] + dp[i+2][1];
                    int dont_sell = dp[i+1][0];
                    dp[i][buy] = max(sell, dont_sell);
                }
            }
        }
        return dp[0][1];
    }
};


// class Solution {
// public:
//     int solve(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
//         if(i >= prices.size()) return 0;

//         if(dp[i][buy] != -1){
//             return dp[i][buy];
//         }

//         if(buy){
//             int take = -prices[i] + solve(i+1, 0, prices, dp);
//             int skip = solve(i+1, 1, prices, dp);
//             return dp[i][buy] = max(take, skip);
//         }
//         else{
//             int sell = prices[i] + solve(i+2, 1, prices, dp);
//             int dont_sell = solve(i+1, 0, prices, dp);
//             return dp[i][buy] = max(sell, dont_sell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>>dp(n+1, vector<int>(2, -1));
//         return solve(0, 1, prices, dp);
//     }
// };