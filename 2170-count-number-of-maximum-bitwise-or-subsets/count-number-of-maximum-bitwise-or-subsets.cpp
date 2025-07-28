// class Solution {
// public:
//     int solve(int i, vector<int>& nums, int currOR, int maxOR, vector<vector<int>>&dp){
//         // Base case
//         if(i >= nums.size()){
//             if(currOR == maxOR){
//                 return 1;
//             }
//             return 0;
//         }

//         if(dp[i][currOR] != -1){
//             return dp[i][currOR];
//         }

//         int include = solve(i+1, nums, currOR | nums[i], maxOR, dp);

//         int exclude = solve(i+1, nums, currOR, maxOR, dp);

//         dp[i][currOR] = include + exclude;
//         return dp[i][currOR];
//     }
//     int countMaxOrSubsets(vector<int>& nums) {
//         int maxOR = 0;
//         for(int& num: nums){
//             maxOR |= num;
//         }

//         int n = nums.size();
//         vector<vector<int>>dp(n+1, vector<int>(maxOR+1, -1));

//         int currOR=0;
//         int ans = solve(0, nums, currOR, maxOR, dp);
//         return ans;
//     }
// };


// class Solution {
// public:
//     int solve(int i, vector<int>& nums, int currOR, int maxOR){
//         // Base case
//         if(i >= nums.size()){
//             if(currOR == maxOR){
//                 return 1;
//             }
//             return 0;
//         }

//         int include = solve(i+1, nums, currOR | nums[i], maxOR);

//         int exclude = solve(i+1, nums, currOR, maxOR);

//         int ans = include + exclude;
//         return ans;
//     }
//     int countMaxOrSubsets(vector<int>& nums) {
//         int maxOR = 0;
//         for(int& num: nums){
//             maxOR |= num;
//         }

//         int currOR=0;
//         int ans = solve(0, nums, currOR, maxOR);
//         return ans;
//     }
// };



class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums, int curr_or, int&max_or, vector<vector<int>>&dp){
        if(i >= n){
            if(curr_or == max_or){
                return 1;
            }
            return 0;
        }

        if(dp[i][curr_or] != -1){
            return dp[i][curr_or];
        }

        // take
        int take = solve(i+1, nums, curr_or|nums[i], max_or, dp);

        // skip
        int skip = solve(i+1, nums, curr_or, max_or, dp);

        int totalCount = take + skip;
        return dp[i][curr_or] = totalCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();

        int max_or = 0;
        for(int& num: nums){
            max_or |= num;
        }
    
        int curr_or = 0;
        vector<vector<int>>dp(n+1, vector<int>(max_or+1, -1));
        return solve(0, nums, curr_or, max_or, dp);
    }
};