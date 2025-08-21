class Solution {
public:
    long long solve(int i, bool flag, vector<int>& nums, vector<vector<long long>>&dp){
        if(i < 0){
            return 0;
        }

        if(dp[i][flag] != -1){
            return dp[i][flag];
        }

        long long skip = solve(i-1, flag, nums, dp);

        long long val = nums[i];
        if(!flag){
            val = -val;
        }
        long long take = val + solve(i-1, !flag, nums, dp);
        long long ans = max(take, skip);
        return dp[i][flag] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n+1, vector<long long>(2, -1));
        return solve(n-1, true, nums, dp);
    }
};


// class Solution {
// public:
//     long long solveUsingRecAndMemo(vector<int>& nums, int i, bool flag, vector<vector<long long>>&dp){
//         if(i >= nums.size()) return 0;

//         if(dp[i][flag] != -1)  return dp[i][flag];

//         long long skip = solveUsingRecAndMemo(nums, i+1, flag, dp);
//         long long value = nums[i];
//         if(flag == false){
//             value = -value;
//         }

//         long long  take  = value +  solveUsingRecAndMemo(nums, i+1, !flag, dp);
//         long long ans = max(take, skip);
//         dp[i][flag] = ans;
//         return dp[i][flag];
//     }

//     long long solveUsingTabulation(vector<int>& nums){
//         int n = nums.size();
//         vector<vector<long long>>dp(n+1, vector<long long>(2, 0));

//         for(int i=1; i<=n; i++){
//             // Even
//             dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
//             // Odd
//             dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);
//         }
//         return max(dp[n][0], dp[n][1]);
//     }
//     long long maxAlternatingSum(vector<int>& nums) {
//         // vector<vector<long long>>dp(nums.size()+1, vector<long long>(2, -1));
//         // long long ans = solveUsingRecAndMemo(nums, 0, true, dp);
//         long long ans = solveUsingTabulation(nums);
//         return ans;
//     }
// };