class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        
        int prev = 0;
        int prevNext = nums[0];
        int curr = 0;

        for(int i=1; i<n; i++){
            curr = max(nums[i]+prev, prevNext);
            prev = prevNext;
            prevNext = curr;
        }
        return curr;
    }
};




// class Solution {
// public:
//     // int robbery(vector<int>& nums, int i){
//     //     // Base case
//     //     if(i >= nums.size()) return 0;

//     //     int robAmt1 = nums[i] + robbery(nums, i + 2);  
//     //     int robAmt2 = 0 + robbery(nums, i+1);
//     //     return max(robAmt1, robAmt2);
//     // }

//     // int robbery(vector<int>& nums, int i, vector<int>&dp){
//     //     // Base case
//     //     if(i >= nums.size()) return 0;

//     //     if(dp[i] != -1) return dp[i];

//     //     int include = nums[i] + robbery(nums, i + 2, dp);  
//     //     int exclude = 0 + robbery(nums, i+1, dp);
//     //     dp[i] = max(include, exclude);
//     //     return dp[i];
//     // }

//     int solveUsingTabulation(vector<int>& nums, int n){
//         vector<int>dp(n, -1);
//         dp[n-1] = nums[n-1];

//         for(int i = n-2; i>= 0; i--){
//            int temp = 0;
//            if(i + 2 < n){
//                 temp = dp[i+2];
//            }
//            int include  = nums[i] + temp;
//            int exclude = 0 + dp[i+1];
//            dp[i] = max(include, exclude);
//         }
//         return dp[0];
//     }

//     int solveUsingSpaceOptm(vector<int>& nums, int n){
//         int next = 0;
//         int prev = nums[n-1];
//         int curr = 0;
//         for(int i =n-2; i>=0; i--){
//             int tempAns = 0;
//             if(i+2 < n){
//                 tempAns = next;
//             }
//             int include  = nums[i] +  tempAns;
//             int exclude = prev;
//             curr = max(include, exclude);
            
//             next = prev;
//             prev = curr;
//         }
//         return prev;
//     }

    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         // vector<int>dp(n+1, -1);
//         // return robbery(nums, 0, dp);
//         // int ans = solveUsingTabulation(nums, n);
//         int ans = solveUsingSpaceOptm(nums, n);
//         return ans;
//     }
// };