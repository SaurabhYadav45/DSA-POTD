class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        // Initialization
        // dp[n][trans] = 0
        // dp[i][2*k] = 0;
        for(int i=n-1; i>=0; i--){
            for(int trans = 2*k-1; trans >= 0; trans--){
                if(trans % 2 == 0){
                    // buy
                    int take = -prices[i] + dp[i+1][trans+1];
                    int skip = dp[i+1][trans];
                    dp[i][trans] = max(take, skip);
                }
                else{ // sell
                    int sell = prices[i] + dp[i+1][trans+1];
                    int dont_sell = dp[i+1][trans];
                    dp[i][trans] = max(sell, dont_sell);
                }
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
//     int solve(int i, int trans, int k, vector<int>& prices, vector<vector<int>>&dp){
//         if(i == prices.size() || trans == 2*k) return 0;

//         if(dp[i][trans] != -1){
//             return dp[i][trans];
//         }

//         if(trans % 2 == 0){
//               // buy
//             int take = -prices[i] + solve(i+1, trans+1, k, prices, dp);
//             int skip = solve(i+1, trans, k, prices, dp);
//             return dp[i][trans] = max(take, skip);
//         }
//         else{ // sell
//             int sell = prices[i] + solve(i+1, trans+1, k, prices, dp);
//             int dont_sell = solve(i+1, trans, k, prices, dp);
//             return dp[i][trans] = max(sell, dont_sell);
//         }
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>>dp(n+1, vector<int>(2*k, -1));
//         // transaction = buy, sell, buy, sell
//         // transaction = (0), (1),  (2), (3)     buy => even && sell => odd
//         return solve(0, 0, k, prices, dp);
//     }
// };