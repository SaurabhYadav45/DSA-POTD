class Solution {
public:
    int solveUsingMemo(vector<int>& nums, int s, int e, vector<int>&dp){
        // Base case
        if(s>e) return 0;
        if(dp[s] != -1) return dp[s];

        int robAmt1 = nums[s] +solveUsingMemo(nums, s+2, e, dp);
        int robAmt2 = 0 + solveUsingMemo(nums, s+1, e, dp);

        dp[s] =  max(robAmt1, robAmt2);
        return dp[s];
    }
    int rob(vector<int>& nums) {
     int n = nums.size();
     if(n == 1) return nums[0];
     if(n == 2) return max(nums[0], nums[1]);

     vector<int>dp(n, -1);
     int option1 = solveUsingMemo(nums, 0, n-2, dp);

     dp = vector<int>(n, -1);
     int option2 = solveUsingMemo(nums, 1, n-1, dp);

     int maxAmt = max(option1, option2);
     return maxAmt;
    }
};