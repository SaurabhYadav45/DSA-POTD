//         **************** Binary Search : Patience Sort *********
class Solution {
public:  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted;
        for(int i=0; i<n; i++){
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if(it == sorted.end()){
                sorted.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return (int)sorted.size();
    }
};

//       ************** Bottom Up **************

// class Solution {
// public:  
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n, 1);
//         int maxLIS = 1;
//         // State Definition :  dp[i] = LIS in nums[0...i];
//         for(int i=1; i<n; i++){
//             for(int j=0; j<i; j++){
//                 if(nums[j] < nums[i]){
//                     dp[i] = max(dp[i], 1 + dp[j]);
//                     maxLIS = max(dp[i], maxLIS);
//                 }
//             }
//         }
//         return maxLIS;
//     }
// };

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