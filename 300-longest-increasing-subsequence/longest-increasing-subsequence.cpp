class Solution {
public:  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int maxLIS = 1;
        // State Definition :  dp[i] = LIS in nums[0...i];
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxLIS = max(dp[i], maxLIS);
                }
            }
        }
        return maxLIS;
    }
};

// class Solution {
// public:  
//     int solve(int i, int prev, vector<int>& nums, vector<vector<int>>&dp){
//         if(i >= nums.size()){
//             return 0;
//         }

//         if(dp[i][prev+1] != -1){
//             return dp[i][prev+1];
//         }

//         int take = 0;
//         if(prev == -1 || nums[i] > nums[prev]){
//             take = 1 + solve(i+1, i, nums, dp);
//         }

//         int skip = solve(i+1, prev, nums, dp);
//         return dp[i][prev+1] = max(take, skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n, vector<int>(n+1, -1));
//         return solve(0, -1, nums, dp);
//     }
// };


// class Solution {
// public:

//     int solveUsingRecAndMemo(vector<int>& nums, int i, int p, vector<vector<int>>&dp){
//         // base case
//         if(i >= nums.size()) return 0;

//         if( p != -1 && dp[i][p] != -1 ){
//              return dp[i][p];
//         }

//         int skip  = solveUsingRecAndMemo(nums, i+1, p, dp);
//         int take = 0;
//         if(p == -1 || nums[p] < nums[i]){
//              take = 1 + solveUsingRecAndMemo(nums, i+1, i, dp);
//         }

//         int ans  = max(take, skip);
//         if(p != -1){
//             dp[i][p] = ans;
//         }
        
//         return ans ;
//     }


//     int solveUsingTabulation(vector<int>& nums){
//         int n = nums.size();
//         vector<int>dp(n+1, 1);
//         int maxLIS = 1;
//         for(int i=0; i< n; i++){
//             for(int j=0; j<i ; j++){
//                 if(nums[j]  < nums[i]){
//                     dp[i] = max(dp[i], dp[j]+1);
//                     maxLIS = max(dp[i], maxLIS);
//                 }
//             }
//         }
//         return maxLIS;
//     }

    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
//         // int ans = solveUsingRecAndMemo(nums, 0, -1, dp);
//         int ans = solveUsingTabulation(nums);
//         return ans;
//     }
// };