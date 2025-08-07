class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int&num : nums){
            sum += num;
        }

        if(sum % 2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<bool>>dp(n+1, vector<bool>(target+1, false));

        // for(int i = 0; i < n+1; i++) {
        //     for(int j = 0; j < target+1; j++) {
        //         if(j == 0)
        //             dp[i][j] = true;  // sum = 0 is always possible (empty subset)
        //         else if(i == 0)
        //             dp[i][j] = false; // non-zero sum with 0 items not possible
        //     }
        // }

        for(int i = 0; i < n+1; i++) {
            dp[i][0] = true;
        }

        // for(int i = 0; i < target+1; i++) {
        //     dp[0][i] = false;
        // }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < target+1; j++) {
                bool take =  false;
                if(nums[i-1] <= j){
                    take = dp[i-1][j-nums[i-1]];
                }
                bool skip = dp[i-1][j];
                dp[i][j] = take || skip;
            }
        }
        return dp[n][target];
    }
};



// class Solution {
// public:
//     bool solve(vector<int>&nums, int n, int sum, vector<vector<int>>&dp){
//         if(sum == 0) return true;
//         if(n == 0){
//             return nums[0] == sum ;
//         }

//         if(dp[n][sum] != -1){
//             return dp[n][sum];
//         }

//         bool take = false;
//         if(nums[n] <= sum){
//             take = solve(nums, n-1, sum-nums[n], dp);
//         }
//         bool skip = solve(nums, n-1, sum, dp);

//         return dp[n][sum] = take || skip;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int&num : nums){
//             sum += num;
//         }

//         if(sum % 2 != 0){
//             return false;
//         }

//         int target = sum/2;

//         vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

//         return solve(nums, n-1, target, dp);
//     }
// };



// class Solution {
// public:
//     int n;
//     bool solve(vector<int>&nums, int i, int target, vector<vector<int>>&dp){

//         if(i >= n || target<0 ) return false;

//         if(target == 0) return true;

//         if(dp[i][target] != -1){
//             return dp[i][target];
//         }

//         bool take = solve(nums, i+1, target-nums[i], dp);
//         bool skip = solve(nums, i+1, target, dp);
//         dp[i][target] =  take||skip;
//         return dp[i][target];
//     }
//     bool canPartition(vector<int>& nums) {
//         n = nums.size();
//         int sum = 0;
//         for(int&num : nums){
//             sum += num;
//         }

//         if(sum % 2 != 0){
//             return false;
//         }

//         int target = sum/2;

//         vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

//         return solve(nums, 0, target, dp);
//     }
// };