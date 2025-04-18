class Solution {
public:
    int n;
    bool solve(vector<int>&nums, int i, int target, vector<vector<int>>&dp){

        if(i >= n || target<0 ) return false;

        if(target == 0) return true;

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool take = solve(nums, i+1, target-nums[i], dp);
        bool skip = solve(nums, i+1, target, dp);
        dp[i][target] =  take||skip;
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int&num : nums){
            sum += num;
        }

        if(sum % 2 != 0){
            return false;
        }

        int target = sum/2;

        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        return solve(nums, 0, target, dp);
    }
};