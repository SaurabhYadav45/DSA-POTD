class Solution {
public:
    int solve(vector<int>& coins, int n, int amount, vector<vector<int>>&dp){
        if(n == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int take = INT_MAX;
        if(coins[n] <= amount){
            take = 1 + solve(coins, n, amount-coins[n], dp);
        }
        int skip = solve(coins, n-1, amount, dp);
        return dp[n][amount] = min(take, skip);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, n-1, amount, dp);

        if(ans >= 1e9) return -1;
        return ans;
    }
};



// class Solution {
// public:
//     int solveUsingRecAndMem(vector<int>& coins, int amount, vector<int>&dp){
//         // Base case
//         if(amount == 0) return 0;
//         int mini = INT_MAX;

//         if(dp[amount] != -1) return dp[amount];

//         for(int i=0; i<coins.size(); i++){
//             int coin = coins[i];
//             if(coin <= amount){
//                 int recKaAns = solveUsingRecAndMem(coins, amount-coin, dp);
//                 if(recKaAns  != INT_MAX){
//                     int ans = 1+recKaAns;
//                     mini = min(mini, ans);
//                 }
//             }
//         }
//         dp[amount] = mini;
//         return dp[amount];
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         // int ans = solve(coins, amount);
//         vector<int>dp(amount + 1, -1);
//         int ans = solveUsingRecAndMem(coins, amount, dp);
//         if(ans == INT_MAX){
//             return -1;
//         }
//         else{
//             return ans;
//         }
//     }
// };