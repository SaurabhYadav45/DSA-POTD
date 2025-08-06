class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);

    int prev = 0;
    int prevNext = nums[0];
    int curr = 0;
    for(int i=1; i<=n-2; i++){
        curr = max(nums[i]+prev, prevNext);
        prev = prevNext;
        prevNext = curr;
    }
    int result1 = curr;

    prev = 0;
    prevNext = nums[1];
    curr = 0;
    for(int i=2; i<=n-1; i++){
        curr = max(nums[i]+prev, prevNext);
        prev = prevNext;
        prevNext = curr;
    }
    int result2 = curr;

    int maxAmt = max(result1, result2);
    return maxAmt;
    }
};



//       ************* Bottom Up **************

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 1) return nums[0];
//     if(n == 2) return max(nums[0], nums[1]);

//     vector<int>dp(n+1, 0);
//     dp[0] = 0;
//     for(int i=1; i<=n-1; i++){
//         int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
//         int skip = dp[i-1];
//         dp[i] = max(steal, skip);
//     }
//     int result1 = dp[n-1];

//     dp.assign(n+1, 0);
//     dp[0] = 0;
//     dp[1] = 0;
//     for(int i=2; i<=n; i++){
//         int steal = nums[i-1] + ((i-2 >= 0) ? dp[i-2] : 0);
//         int skip = dp[i-1];
//         dp[i] = max(steal, skip);
//     }
//     int result2 = dp[n];

//     int maxAmt = max(result1, result2);
//     return maxAmt;
//     }
// };



//           ********** Recursion + Memoization *************

// class Solution {
// public:
//     int solveUsingMemo(vector<int>& nums, int i, int n, vector<int>&dp){
//         // Base case
//         if(i>n) return 0;
//         if(dp[i] != -1) return dp[i];

//         int robAmt1 = nums[i] + solveUsingMemo(nums, i+2, n, dp);
//         int robAmt2 = solveUsingMemo(nums, i+1, n, dp);

//         dp[i] =  max(robAmt1, robAmt2);
//         return dp[i];
//     }
//     int rob(vector<int>& nums) {
//      int n = nums.size();
//      if(n == 1) return nums[0];
//      if(n == 2) return max(nums[0], nums[1]);

//      vector<int>dp(n, -1);
//      int option1 = solveUsingMemo(nums, 0, n-2, dp);

//      dp = vector<int>(n, -1);
//      int option2 = solveUsingMemo(nums, 1, n-1, dp);

//      int maxAmt = max(option1, option2);
//      return maxAmt;
//     }
// };