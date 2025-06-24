// class Solution {
// public:
//     int n;
//     int solve(vector<int>& nums, int target, vector<int>&dp){
//         if(target == 0){
//             return 1;
//         }
//         if(target < 0){
//             return 0;
//         }

//         if(dp[target] != -1){
//             return dp[target];
//         }
//         int result = 0;

//         for(int i=0; i<n; i++){
//             int take = solve(nums, target-nums[i], dp);
//             result += take;
//         }
//         return dp[target] = result;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         n = nums.size();
//         vector<int>dp(target+1,-1);
//         return solve(nums, target, dp);
//     }
// };


class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>&dp){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(i >= n){
            return 0;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int take = solve(0, nums, target-nums[i], dp);
        int skip = solve(i+1, nums, target, dp);
        return dp[i][target] = take + skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(0, nums, target, dp);
    }
};