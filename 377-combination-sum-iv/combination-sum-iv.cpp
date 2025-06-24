class Solution {
public:
    int n;
    int solve(vector<int>& nums, int target, vector<int>&dp){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }
        int result = 0;

        for(int i=0; i<n; i++){
            int take = solve(nums, target-nums[i], dp);
            result += take;
        }
        return dp[target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        vector<int>dp(target+1,-1);
        return solve(nums, target, dp);
    }
};


// class Solution {
// public:
//     int n;
//     int solve(vector<int>& nums, int target){
//         if(target == 0){
//             return 1;
//         }
//         if(target < 0){
//             return 0;
//         }
//         int result = 0;

//         for(int i=0; i<n; i++){
//             int take = solve(nums, target-nums[i]);
//             result += take;
//         }
//         return result;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         n = nums.size();
        
//         return solve(nums, target);
//     }
// };