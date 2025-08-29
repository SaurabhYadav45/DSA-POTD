class Solution {
public:
    int solve(int i, int trans, int k, vector<int>& prices, vector<vector<int>>&dp){
        if(i == prices.size() || trans == 2*k) return 0;

        if(dp[i][trans] != -1){
            return dp[i][trans];
        }

        if(trans % 2 == 0){
              // buy
            int take = -prices[i] + solve(i+1, trans+1, k, prices, dp);
            int skip = solve(i+1, trans, k, prices, dp);
            return dp[i][trans] = max(take, skip);
        }
        else{ // sell
            int sell = prices[i] + solve(i+1, trans+1, k, prices, dp);
            int dont_sell = solve(i+1, trans, k, prices, dp);
            return dp[i][trans] = max(sell, dont_sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k, -1));
        // transaction = buy, sell, buy, sell
        // transaction = (0), (1),  (2), (3)     buy => even && sell => odd
        return solve(0, 0, k, prices, dp);
    }
};