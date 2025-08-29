class Solution {
public:
    int solve(int i, int trans, vector<int>& prices, vector<vector<int>>&dp){
        if(i == prices.size() || trans == 4) return 0;

        if(dp[i][trans] != -1){
            return dp[i][trans];
        }

        if(trans % 2 == 0){
              // buy
            int take = -prices[i] + solve(i+1, trans+1, prices, dp);
            int skip = solve(i+1, trans, prices, dp);
            return dp[i][trans] = max(take, skip);
        }
        else{ // sell
            int sell = prices[i] + solve(i+1, trans+1, prices, dp);
            int dont_sell = solve(i+1, trans, prices, dp);
            return dp[i][trans] = max(sell, dont_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(4, -1));
        // transaction = buy, sell, buy, sell
        // transaction = (0), (1),  (2), (3)     buy => even && sell => odd
        return solve(0, 0, prices, dp);
    }
};


//         ********************* Approach -1 **********************

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
//         // Initalization
//         // t[n][buy][cap] = 0
//         // t[idx][buy][0] = 0;

//         for(int i=n-1; i>=0; i--){
//             for(int buy = 0; buy <= 1; buy++){
//                 for(int cap = 1; cap <=2; cap++){
//                     if(buy){
//                         int take = -prices[i] + dp[i+1][0][cap];
//                         int skip = dp[i+1][1][cap];
//                         dp[i][buy][cap] = max(take, skip);
//                     }
//                     else{
//                         // sell
//                         int sell = prices[i] + dp[i+1][1][cap-1];
//                         int dont_sell = dp[i+1][0][cap];
//                         dp[i][buy][cap] = max(sell, dont_sell);
//                     }
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
// };


// class Solution {
// public:
//     int t[100001][2][3];
//     int solve(int i, int buy, int cap, vector<int>& prices){
//         if(i >= prices.size()) return 0;
//         if(cap == 0) return 0;

//         if(t[i][buy][cap] != -1){
//             return t[i][buy][cap];
//         }

//         if(buy){
//             int take = -prices[i] + solve(i+1, 0, cap, prices);
//             int skip = solve(i+1, 1, cap, prices);
//             return t[i][buy][cap] = max(take, skip);
//         }
//         else{
//             // sell
//             int sell = prices[i] + solve(i+1, 1, cap-1, prices);
//             int dont_sell = solve(i+1, 0, cap, prices);
//             return t[i][buy][cap] = max(sell, dont_sell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         memset(t, -1, sizeof(t));
//         return solve(0, 1, 2, prices);
//     }
// };